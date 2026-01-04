PORTNAME=	libcreg
DISTVERSION=	experimental-20240419
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libcreg/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to access the Windows 9x/Me Registry File format
WWW=		https://github.com/libyal/libcreg

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-python
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		fuse libtool pathfix pkgconfig python
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
