# New ports collection makefile for:   libhid
# Date created:        16 July 2007
# Whom:                ntarmos@ceid.upatras.gr
#
# $FreeBSD$
#

PORTNAME=	libhid
PORTVERSION=	0.2.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1958/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A user-space HID access library written in C

MAN1=		libhid-detach-device.1
MANCOMPRESSED=	no
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes

BUILD_DEPENDS+=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/swig1.3:${PORTSDIR}/devel/swig13

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} --mandir=${MANPREFIX}/man --without-doxygen

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb
.endif

.include <bsd.port.post.mk>
