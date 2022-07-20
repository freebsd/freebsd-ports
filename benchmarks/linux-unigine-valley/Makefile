PORTNAME=	unigine-valley
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	benchmarks linux
MASTER_SITES=	https://assets.unigine.com/d/
PKGNAMEPREFIX=	linux-
DISTNAME=	Unigine_Valley-${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Unigine Valley benchmark (basic version for GNU/Linux)

LICENSE=	Proprietary
LICENSE_NAME=	Unigine "Basic" License
LICENSE_FILE=	${.CURDIR}/pkg-license
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	amd64 i386
USES=		linux shebangfix
USE_LINUX=	dri openal-soft xorglibs
USE_LDCONFIG=	yes
NO_BUILD=	yes

SHEBANG_FILES=	valley
bash_CMD=	${LINUXBASE}/bin/bash
SUB_FILES=	wrapper.sh

DESKTOP_ENTRIES="Unigine Valley" "${COMMENT}" "${DATADIR}/data/launcher/icon.png" \
		"${PKGNAMEPREFIX}${PORTNAME}" "Game;" false

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAIL} -n 1491255 ${DISTDIR}/${DISTFILES} | ${TAR} xzf - -C ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./data ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./bin ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./documentation ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/valley ${STAGEDIR}${DATADIR}/valley

.include <bsd.port.mk>
