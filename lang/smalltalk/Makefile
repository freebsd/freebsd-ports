# New ports collection makefile for:	smalltalk
# Version required:	1.6.2
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

DISTNAME=	smalltalk-1.6.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	smalltalk

MAINTAINER=	alex@big.endian.de

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-optimize --with-readline

MAN1=		gst.1

# Set all-target to test the stuff
ALL_TARGET=	all check

.include <bsd.port.mk>
