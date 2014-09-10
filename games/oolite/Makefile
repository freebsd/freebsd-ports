# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=		oolite
PORTVERSION=		1.76
PORTREVISION=	4
CATEGORIES=		games gnustep
MASTER_SITES=		${MASTER_SITE_BERLIOS} http://jens.ayton.se/oolite/deps/:js
MASTER_SITE_SUBDIR=	oolite-linux
DISTFILES=		${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
			firefox-4.0.source.js-only.tbz:js
DIST_SUBDIR=		oolite
EXTRACT_ONLY=		${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		avg@icyb.net.ua
COMMENT=		Trade and combat space simulator, clone of Elite

BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip \
			${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=		libespeak.so:${PORTSDIR}/audio/espeak \
			libnspr4.so:${PORTSDIR}/devel/nspr

USES=			gmake perl5 tar:bzip2
USE_GL=			yes
USE_SDL=		mixer image gfx
USE_GNUSTEP=		yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_BUILD=	yes
USE_MAKEFILE=		yes
ALL_TARGET=		release-deployment
USE_PERL5=		build
USE_PYTHON_BUILD=	yes

SUB_FILES=		pkg-message
PKGMESSAGE=		${WRKDIR}/pkg-message

WRKSRC=			${WRKDIR}/${PORTNAME}-source-${PORTVERSION}

post-extract:
	@(cd ${WRKSRC}/deps/Cross-platform-deps && \
		${BZIP2_CMD} -dc ${_DISTDIR}/firefox-4.0.source.js-only.tbz | ${TAR} -xf - && \
		${MV} mozilla-2.0 mozilla && \
		${ECHO_CMD} 'http://jens.ayton.se/oolite/deps/firefox-4.0.source.js-only.tbz' > mozilla/current.url \
	)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications
	${CP} -R ${WRKSRC}/oolite.app ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/oolite.app/oolite
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/installers/FreeDesktop/oolite-icon.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
