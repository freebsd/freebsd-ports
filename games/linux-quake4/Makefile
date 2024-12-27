PORTNAME=	quake4
PORTVERSION=	1.4.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	IDSOFTWARE/quake4/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 4 for Linux
WWW=		http://www.quake4game.com/

# Converted from NO_CDROM
LICENSE=	IDSOFTWARE
LICENSE_NAME=	IDSOFTWARE
LICENSE_TEXT=	Redistribution is limited, see license
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		linux
USE_LINUX=	sdl12

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST+=	Q4DIR="${Q4DIR}"

NO_WRKSUBDIR=	yes

Q4DIR=		lib/${PORTNAME}
PLIST_SUB+=	Q4DIR="${Q4DIR}" \
		LINUXBASE="${LINUXBASE}"

OPTIONS_DEFINE=	THREADS GERMANY DOCS
OPTIONS_DEFAULT=	THREADS
OPTIONS_SUB=	yes

GERMANY_DESC=	Germany version

.include <bsd.port.pre.mk>

do-extract:
	@cd ${WRKSRC} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${Q4DIR}
.for FILE in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/${FILE}.x86 ${STAGEDIR}${PREFIX}/${Q4DIR}
.endfor

	# Punkbuster
	@${MKDIR} ${STAGEDIR}${PREFIX}/${Q4DIR}/pb/htm
	@${MKDIR} ${STAGEDIR}${PREFIX}/${Q4DIR}/q4base
	@cd ${WRKSRC} && \
		${FIND} -E pb -type f -iregex ".*\.(so)" \
			-exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${Q4DIR}/{}" \; && \
		${FIND} -E pb/htm -type f -iregex ".*\.(htm)" \
			-exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${Q4DIR}/{}" \;
	# Q4base
	 @cd ${WRKSRC} && \
		${FIND} -E q4base -type f -iregex ".*\.(cfg|scriptcfg|pk4|off)" \
			-exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${Q4DIR}/{}" \;

# All version (except germany) or only germany version
do-install-GERMANY-on:
	@cd ${WRKSRC}/germany && \
		${FIND} -E q4base -type f -iregex ".*\.(pk4)" \
			-exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${Q4DIR}/{}" \;

do-install-GERMANY-off:
	@cd ${WRKSRC}/us && \
		${FIND} -E q4base -type f -iregex ".*\.(pk4)" \
			-exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${Q4DIR}/{}" \;

# Documentation
do-install-DOCS-on:
	@cd ${WRKSRC}/Docs && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DOCSDIR}/{}" \;
	${INSTALL_DATA} ${WRKSRC}/License.txt ${STAGEDIR}${DOCSDIR}/LICENSE && \
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README && \
	${INSTALL_DATA} ${WRKSRC}/pb/PBEULA.txt ${STAGEDIR}${DOCSDIR}/PBEULA

do-install-THREADS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}quake4smp.sh ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}quake4smp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/quake4smp.x86 ${STAGEDIR}${PREFIX}/${Q4DIR}

.include <bsd.port.post.mk>
