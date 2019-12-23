# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvmdk
PORTVERSION=	20191221
DISTVERSIONPREFIX=	alpha-
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libvmdk/releases/download/${PORTVERSION}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to access the VMware Virtual Disk (VMDK) format

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
USES=		fuse libtool pathfix pkgconfig python:3.5+
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
