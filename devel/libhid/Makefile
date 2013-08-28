# Created by: ntarmos@ceid.upatras.gr
# $FreeBSD$

PORTNAME=	libhid
PORTVERSION=	0.2.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1958/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	User-space HID access library written in C

MAN1=		libhid-detach-device.1
MANCOMPRESSED=	no
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		gmake

BUILD_DEPENDS+=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/swig1.3:${PORTSDIR}/devel/swig13

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} --mandir=${MANPREFIX}/man --without-doxygen --disable-werror

EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb

.include <bsd.port.mk>
