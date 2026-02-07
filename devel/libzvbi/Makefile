PORTNAME=	libzvbi
PORTVERSION=	0.2.44
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Routines to access raw VBI capture devices
WWW=		https://github.com/zapping-vbi/zvbi

LICENSE=	GPLv2+

LIB_DEPENDS+=	libpng.so:graphics/png \
		libunicode.so:devel/libunicode

USES=		autoreconf gettext iconv libtool localbase pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doxygen
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	zapping-vbi
GH_PROJECT=	zvbi

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=nls
NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's|#cpu (\([^)]*\))|defined(__\1__)|g' \
		${WRKSRC}/src/misc.h \
		${WRKSRC}/src/exp-gfx.c

.include <bsd.port.mk>
