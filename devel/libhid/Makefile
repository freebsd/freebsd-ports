# Created by: ntarmos@ceid.upatras.gr
# $FreeBSD$

PORTNAME=	libhid
PORTVERSION=	0.2.16
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1958/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	User-space HID access library written in C

BUILD_DEPENDS=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/swig1.3:${PORTSDIR}/devel/swig13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doxygen --disable-werror
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix
USE_LDCONFIG=	yes
USE_PYTHON=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb

.include <bsd.port.mk>
