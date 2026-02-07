PORTNAME=	aobook
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
CATEGORIES=	japanese

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Aozora Bunko Text Viewer
WWW=		https://azelpg.gitlab.io/azsky2/soft/aobook.html

LICENSE=	MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_OFL11=	${WRKSRC}/OFL.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png

USES=		compiler:c11 iconv:wchar_t jpeg ninja pkgconfig xorg

USE_GITLAB=	yes
GL_ACCOUNT=	azelpg

USE_XORG=	x11 xcursor xext

GNU_CONFIGURE=	yes

ALL_TARGET=	${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
