# $FreeBSD$

PORTNAME=	libretro-yabause
PORTVERSION=	0.20210204
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Saturn emulator for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	yabause
GH_TAGNAME=	ea5b118

PLIST_FILES=	lib/libretro/yabause_libretro.so

MAKEFILE=	Makefile.freebsd

.include <bsd.port.pre.mk>

post-patch:
.if ${ARCH} != "amd64"
	@${REINPLACE_CMD} -e "s/HAVE_SSE = 1/HAVE_SSE = 0/" ${WRKSRC}/yabause/src/libretro/Makefile
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/yabause/src/libretro/yabause_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.post.mk>
