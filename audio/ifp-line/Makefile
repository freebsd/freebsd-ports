# ex:ts=8
# New ports collection makefile for:	ifp-line
# Date created:			Sep 21, 2004
# Whom:				riggs
#
# $FreeBSD$
#

PORTNAME=	ifp-line
PORTVERSION=	0.2.4.6
CATEGORIES=	audio
MASTER_SITES=	SF/ifp-driver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	riggs@rrr.de
COMMENT=	Command line interface to iRiver music players

MAN1=		ifp.1

PLIST_FILES+=	bin/ifp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

post-patch:
.if ${OSVERSION} >= 800069
	@${REINPLACE_CMD} -E -e 's,`libusb-config --cflags`,,g' \
		-e 's,`libusb-config --libs`,-lusb,g' ${WRKSRC}/Makefile
.endif

post-install:
	@${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.post.mk>
