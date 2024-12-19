PORTNAME=	libewf
PORTVERSION=	20140816
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libewf-legacy/releases/download/${PORTVERSION}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library for support of the Expert Witness Compression Format (EWF)
WWW=		https://github.com/libyal/libewf-legacy

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsmdev.so:devel/libsmdev \
		libsmraw.so:devel/libsmraw \
		libuuid.so:misc/libuuid

USES=		fuse libtool pathfix pkgconfig python
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-python --with-libsmdev=${LOCALBASE} \
		--with-libsmraw=${LOCALBASE} \
		--with-libuuid=${LOCALBASE} --with-openssl=no
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
