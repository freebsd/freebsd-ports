# New ports collection makefile for:	ksetispy
# Date created:		Sat Jan  5 14:44:45 BRST 2002
# Whom:			Hammurabi Mendes <hmendes_br@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	ksetispy
PORTVERSION=	0.3.5
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hmendes_br@yahoo.com

USE_QT_VER=	2
USE_KDEBASE_VER=2

GNU_CONFIGURE=	yes

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "===> Define WITH_OPTIMIZED_CFLAGS to enable additional compilation"
	@${ECHO_MSG} "===> optimizations."
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's/-O2//' ${CONFIGURE_WRKSRC}/configure
.endif

.include <bsd.port.mk>
