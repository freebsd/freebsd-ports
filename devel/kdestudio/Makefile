# New ports collection makefile for:	kdestudio
# Date created:			Tuesday January 16, 2001
# Whom:				Trenton Schulz
#
# $FreeBSD$
#

PORTNAME=	kdestudio
PORTVERSION=	2.0.0
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.thekompany.com/pub/KDE_Studio/source/ \
		http://gauss.cord.edu/homepages/twschulz/demo/

MAINTAINER=	twschulz@cord.edu

USE_KDELIBS_VER=2
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

pre-configure:
	@/usr/bin/find ${WRKSRC} -name Makefile.in | /usr/bin/xargs ${PERL} -pi -e "s/CXXFLAGS = -O2 -Wall/#CXXFLAGS = do not touch me/"

.include <bsd.port.mk>
