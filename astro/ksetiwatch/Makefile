# New ports collection makefile for:	ksetiwatch
# Date created:				17 January 2001
# Whom:					Sverre Valgeirsson <sverre@k9k203-3.kam.afb.lu.se>
#
# $FreeBSD$
#

PORTNAME=	ksetiwatch
PORTVERSION=	2.2.0
CATEGORIES=	astro kde
MASTER_SITES=	http://download.sourceforge.net/ksetiwatch/

MAINTAINER=	sverrir@hem.passagen.se

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes

pre-configure:
	${PERL} -pi.orig -e "s@-lqt@-lqt2@g" ${WRKSRC}/ksetiwatch/Makefile.in
	${PERL} -pi.orig -e "s@-lqt@-lqt2@g; s@libqt\.@libqt2\.@g" ${WRKSRC}/configure

.include <bsd.port.mk>
