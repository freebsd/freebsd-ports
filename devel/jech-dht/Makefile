# New ports collection makefile for: jech-dht
# Date created: July 28, 2012
# Whom:		Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	dht
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://www.pps.univ-paris-diderot.fr/~jch/software/files/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Mainline variant of Kademlia Distributed Hash Table (DHT)

LICENSE=	MIT

MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

pre-su-install:
	${MKDIR} ${PREFIX}/include/dht

.include <bsd.port.mk>
