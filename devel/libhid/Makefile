# Created by: ntarmos@ceid.upatras.gr
# $FreeBSD$

PORTNAME=	libhid
PORTVERSION=	0.2.16
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://alioth-archive.debian.org/releases/libhid/libhid/${PORTVERSION}/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	User-space HID access library written in C

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl \
		${LOCALBASE}/bin/swig:devel/swig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-doxygen --disable-werror
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix python:2.7
USE_LDCONFIG=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb

post-patch:
	@${REINPLACE_CMD} -e "s/required=1\.3/required=3.0/g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
