# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	schism
PORTVERSION=	20160913
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

USES=		autoreconf python compiler:c++11-lib
USE_SDL=	sdl
USE_XORG=	x11 xext xv
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	schismtracker
GH_PROJECT=	schismtracker

PLIST_FILES=	bin/${PORTNAME}

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/schismtracker ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
