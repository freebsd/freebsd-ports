# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	dht
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://www.pps.univ-paris-diderot.fr/~jch/software/files/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Mainline variant of Kademlia Distributed Hash Table (DHT)

LICENSE=	MIT

MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes

NO_STAGE=	yes
pre-su-install:
	${MKDIR} ${PREFIX}/include/dht

.include <bsd.port.mk>
