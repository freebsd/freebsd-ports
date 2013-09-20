# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	quake4
PORTVERSION=	1.4.2
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|quake4/linux/|} \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Quake 4 for Linux

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12
NO_WRKSUBDIR=	yes
NO_CDROM=	Redistribution is limited, see license
NO_PACKAGE=	Package will be 280MB, set FORCE_PACKAGE if you really want it
Q4DIR=		lib/${PORTNAME}
PLIST_SUB+=	Q4DIR="${Q4DIR}" \
		LINUXBASE="${LINUXBASE}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	THREADS GERMANY
GERMANY_DESC=	Germany version

OPTIONS_DEFAULT=	THREADS

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
.else
PLIST_SUB+=	THREADS="@comment "
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
.for FILE in quake4 q4ded quake4smp
	${BRANDELF} -t Linux ${WRKSRC}/bin/FreeBSD/x86/${FILE}.x86

	# Startup scripts
	@${SED} \
		-e 's|@Q4DIR@|${PREFIX}/${Q4DIR}|' \
		-e 's|@APP@|${FILE}.x86|' \
		${FILESDIR}/run.sh.in > ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh
.endfor

do-install:
	# Executables
	@${MKDIR} ${PREFIX}/${Q4DIR}
.for FILE in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/${FILE}.x86 ${PREFIX}/${Q4DIR}
.endfor
.if ${PORT_OPTIONS:MTHREADS}
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}quake4smp.sh ${PREFIX}/bin/${PKGNAMEPREFIX}quake4smp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/quake4smp.x86 ${PREFIX}/${Q4DIR}
.endif

	# Punkbuster
	@${MKDIR} ${PREFIX}/${Q4DIR}/pb/htm
	@${MKDIR} ${PREFIX}/${Q4DIR}/q4base
	@cd ${WRKSRC} && \
		${FIND} -E pb -type f -iregex ".*\.(so)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \; && \
		${FIND} -E pb/htm -type f -iregex ".*\.(htm)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \;
	# Q4base
	 @cd ${WRKSRC} && \
		${FIND} -E q4base -type f -iregex ".*\.(cfg|scriptcfg|pk4|off)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \;

	# All version (except germany) or only germany version
.if ${PORT_OPTIONS:MGERMANY}
	@cd ${WRKSRC}/germany && \
		${FIND} -E q4base -type f -iregex ".*\.(pk4)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \;
.else
	@cd ${WRKSRC}/us && \
		${FIND} -E q4base -type f -iregex ".*\.(pk4)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \;
.endif

	# Documentation
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/Docs && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}/LICENSE && \
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README && \
	${INSTALL_DATA} ${WRKSRC}/pb/PBEULA.txt ${DOCSDIR}/PBEULA
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
