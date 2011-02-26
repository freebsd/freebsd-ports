# Ports collection makefile for:  pear-Net_DNS
# Date created:			  2006/12/22
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	Net_DNS
PORTVERSION=	1.0.7
CATEGORIES=	dns net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Resolver library used to communicate with a DNS server

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

PEAR_CATSRC=	yes
PORTSCOUT=	skipv:1.00b2,1.00b1
USE_PHP=	mhash
CATEGORY=	Net
FILES=		DNS/RR/A.php DNS/RR/AAAA.php DNS/RR/CNAME.php DNS/RR/HINFO.php \
		DNS/RR/MX.php DNS/RR/NAPTR.php DNS/RR/NS.php DNS/RR/PTR.php \
		DNS/RR/SOA.php DNS/RR/SRV.php DNS/RR/TSIG.php DNS/RR/TXT.php \
		DNS/Header.php DNS/Packet.php DNS/Question.php DNS/Resolver.php \
		DNS/RR.php DNS.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
