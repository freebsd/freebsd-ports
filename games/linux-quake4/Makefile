# New ports collection makefile for:	Quake 4
# Date created:				21 Oct 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	quake4
PORTVERSION=	1.0.6
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|quake4/linux/old/|} \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Quake 4 for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386 amd64
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
Q4DIR=		lib/${PORTNAME}/
PLIST_SUB+=	Q4DIR="${Q4DIR}"
SUB_FILES=	pkg-message

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
.for i in quake4 q4ded
	${BRANDELF} -t Linux ${WRKSRC}/bin/FreeBSD/x86/$i.x86

	# Startup scripts
	@${SED} \
		-e 's|@Q4DIR@|${PREFIX}/${Q4DIR}|' \
		-e 's|@APP@|$i.x86|' \
		${FILESDIR}/run.sh.in > ${WRKSRC}/$i.sh
.endfor

do-install:
	# Executables
	@${MKDIR} ${PREFIX}/${Q4DIR}
.for i in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/$i.sh ${PREFIX}/bin/$i
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/$i.x86 ${PREFIX}/${Q4DIR}/
.endfor

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
		${FIND} -E q4base -type f -iregex ".*\.(cfg|scriptcfg|pk4)" \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/${Q4DIR}/{}" \;

	# Documentation
.if !defined (NOPORTDOCS)
	@cd ${WRKSRC}/Docs && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}/LICENSE && \
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README && \
	${INSTALL_DATA} ${WRKSRC}/pb/PBEULA.txt ${DOCSDIR}/PBEULA
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
