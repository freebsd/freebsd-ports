# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevt
DISTVERSION=	alpha-20191104
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libevt/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tooling to access the Windows Event Log (EVT) format

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfwnt.so:devel/libfwnt \
		libregf.so:devel/libregf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python \
		--with-libfwnt=${LOCALBASE} --with-libregf=${LOCALBASE}
CONFIGURE_ENV= PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		libtool pathfix python:3.5+
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
