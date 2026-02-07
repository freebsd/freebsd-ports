PORTNAME=	libpff
DISTVERSIONPREFIX=	alpha-
DISTVERSION=	20231205
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libpff/releases/download/${DISTVERSION}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to access the PFF and the OFF formats
WWW=		https://github.com/libyal/libpff

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfwnt.so:devel/libfwnt
BUILD_DEPENDS=	${PY_SETUPTOOLS}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-python --with-libfwnt=${LOCALBASE}
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		cpe libtool pathfix python
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
