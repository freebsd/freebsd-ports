# New ports collection makefile for:	piklab
# Date created:		2007-11-19
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	piklab
PORTVERSION=	0.15.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE IDE for microcontroller development

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes

MAN1=		piklab-hex.1 piklab-prog.1 piklab.1x

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
. else
CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb"
.endif

.include <bsd.port.post.mk>
