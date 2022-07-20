#
# The distfile for this port is quite huge (1.5GB); you might consider
# fetching it via BitTorrent instead:
#   https://assets.unigine.com/d/Unigine_Superposition-1.1.run.torrent
#   magnet:?xt=urn:btih:727718DF8E15006FE961EB2458231AC578D7E172

PORTNAME=	unigine-superposition
PORTVERSION=	1.1
CATEGORIES=	benchmarks linux
MASTER_SITES=	https://assets.unigine.com/d/
PKGNAMEPREFIX=	linux-
DISTNAME=	Unigine_Superposition-${PORTVERSION}
EXTRACT_SUFX=	.run

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Unigine Superposition benchmark (basic version for GNU/Linux)

LICENSE=	Proprietary
LICENSE_NAME=	Unigine "Basic" License
LICENSE_FILE=	${.CURDIR}/pkg-license
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	amd64
USES=		linux
USE_LINUX=	dbuslibs dri openal-soft xorglibs
USE_LDCONFIG=	yes
NO_BUILD=	yes

SUB_FILES=	wrapper.sh

DESKTOP_ENTRIES="Unigine Superposition" "${COMMENT}" "Superposition" \
		"${PKGNAMEPREFIX}${PORTNAME}" "Launcher;Benchmark;" false

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAIL} -n 5406267 ${DISTDIR}/${DISTFILES} | ${TAR} xzf - -C ${WRKSRC}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "bin data docs" ${STAGEDIR}${DATADIR}
	${CHMOD} +x ${STAGEDIR}${DATADIR}/bin/launcher \
		${STAGEDIR}${DATADIR}/bin/superposition \
		${STAGEDIR}${DATADIR}/bin/superposition_cli
	${INSTALL_PROGRAM} ${WRKSRC}/Superposition ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
.for s in 16 24 32 48 64 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/superposition_icon_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/Superposition.png
.endfor

.include <bsd.port.mk>
