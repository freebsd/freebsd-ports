# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=		oolite
PORTVERSION=		1.76
PORTREVISION=	1
CATEGORIES=		games gnustep
MASTER_SITES=		${MASTER_SITE_BERLIOS} http://jens.ayton.se/oolite/deps/:js
MASTER_SITE_SUBDIR=	oolite-linux
DISTFILES=		${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
			firefox-4.0.source.js-only.tbz:js
DIST_SUBDIR=		oolite
EXTRACT_ONLY=		${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		avg@icyb.net.ua
COMMENT=		Trade and combat space simulator, clone of Elite

FETCH_ARGS+=		-a

WRKSRC=			${WRKDIR}/${PORTNAME}-source-${PORTVERSION}

BUILD_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS+=		espeak:${PORTSDIR}/audio/espeak
LIB_DEPENDS+=		nspr4:${PORTSDIR}/devel/nspr

USE_BZIP2=		yes
USE_GL=			yes
USE_SDL=		mixer image gfx
USE_GNUSTEP=		yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_BUILD=	yes
USE_MAKEFILE=		yes
USE_GMAKE=		yes
ALL_TARGET=		release-deployment
USES=		perl5
USE_PERL5=	build
USE_PYTHON_BUILD=	yes

SUB_FILES=		pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

NO_STAGE=	yes
post-extract:
	@(cd ${WRKSRC}/deps/Cross-platform-deps && \
		${BZIP2_CMD} -dc ${_DISTDIR}/firefox-4.0.source.js-only.tbz | ${TAR} -xf - && \
		${MV} mozilla-2.0 mozilla && \
		${ECHO} 'http://jens.ayton.se/oolite/deps/firefox-4.0.source.js-only.tbz' > mozilla/current.url \
	)

do-install:
	${MKDIR} ${GNUSTEP_PREFIX}/Local/Applications
	${CP} -R ${WRKSRC}/oolite.app ${GNUSTEP_PREFIX}/Local/Applications
	${STRIP_CMD} ${GNUSTEP_PREFIX}/Local/Applications/oolite.app/oolite
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite-icon.png ${PREFIX}/share/pixmaps/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
