# New ports collection makefile for:	sdts++
# Date created:         08 Feb 2000
# Whom:                 erik@habatech.no
#
# $FreeBSD$
#

PORTNAME=	sdts++
PORTVERSION=	1.0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://www.clark.net/~mcoletti/sdts/
#		ftp://resdgw17.er.usgs.gov/pub/sdtsxx/

MAINTAINER=	erik@habatech.no

GNU_CONFIGURE=	yes

post-install:
.for info in sdts++.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
