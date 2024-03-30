PORTNAME=	schismtracker
DISTVERSION=	20240328
DISTVERSIONSUFFIX=	.source
CATEGORIES=	audio
MASTER_SITES=	https://github.com/schismtracker/schismtracker/releases/download/${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker
WWW=		https://schismtracker.org/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc powerpc64 powerpc64le

USES=		compiler:c++11-lib desktop-file-utils localbase python sdl xorg
USE_SDL=	sdl2
USE_XORG=	x11 xext xv
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/schismtracker \
		share/man/man1/schismtracker.1.gz \
		share/applications/schism.desktop \
		share/pixmaps/schism-icon-128.png \
		share/pixmaps/schism-itf-icon-128.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/fd.org/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/schism-icon-128.png \
		${WRKSRC}/icons/schism-itf-icon-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
