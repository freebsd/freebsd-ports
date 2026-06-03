PORTNAME=	libevt
DISTVERSION=	alpha-20240421
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libevt/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tooling to access the Windows Event Log (EVT) format
WWW=		https://github.com/libyal/libevt

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfwnt.so:devel/libfwnt \
		libregf.so:devel/libregf
BUILD_DEPENDS=	${PY_SETUPTOOLS}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-python \
		--with-libfwnt=${LOCALBASE} --with-libregf=${LOCALBASE}
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		cpe libtool pathfix python
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
