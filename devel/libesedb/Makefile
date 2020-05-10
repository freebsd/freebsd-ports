# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libesedb
# If/When moving from experimental to alpha, switch to DISTVERSIONPREFIX to prevent PORTEPOCH
DISTVERSION=	experimental-20200418
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libesedb/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to access the ESEDB format

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfwnt.so:devel/libfwnt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libfwnt=${LOCALBASE}
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		libtool pathfix python:3.5+
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
