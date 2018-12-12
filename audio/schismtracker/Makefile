# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	schismtracker
PORTVERSION=	20180810
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

USES=		autoreconf python compiler:c++11-lib desktop-file-utils
USE_SDL=	sdl
USE_XORG=	x11 xext xv
GNU_CONFIGURE=	yes

USE_GITHUB=	yes

# if you touch these make sure configure finds X11/XKBlib.h presence
LDFLAGS+=	`sdl-config --libs`
LIBS+=		-lm -lX11
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^\(AC_INIT.*\)\[last_git_commit\]|\1${PORTVERSION}|" \
		-e '/^m4_define.*last_git_commit.*git/d' \
			${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^schismtracker_LDADD/d' ${WRKSRC}/Makefile.am

post-install:
	${INSTALL_DATA} ${WRKSRC}/sys/fd.org/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/schism-icon-128.png \
		${WRKSRC}/icons/schism-itf-icon-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
