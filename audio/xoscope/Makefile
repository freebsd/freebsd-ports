# ports collection makefile for:	xoscope
# Date created:		March 29, 2008
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	xoscope
PORTVERSION=	1.12
CATEGORIES=	audio hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xoscope
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Sound card oscilloscope

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_XORG=	x11
ONLY_FOR_ARCHS=	i386

MAN1=		xoscope.1 oscope.1

.include <bsd.port.mk>
