# Ports collection makefile for:  pear-Net_DNS2
# Date created:		          Oct 27, 2010
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net_DNS2
PORTVERSION=	1.0.0
CATEGORIES=	dns net pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PHP5 Resolver library used to communicate with a DNS server

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Net/DNS2.php \
		Net/DNS2/BitMap.php Net/DNS2/Exception.php Net/DNS2/Header.php \
		Net/DNS2/Lookups.php Net/DNS2/Packet/Request.php Net/DNS2/Packet/Response.php \
		Net/DNS2/Packet.php Net/DNS2/Question.php Net/DNS2/RR/A.php \
		Net/DNS2/RR/AAAA.php Net/DNS2/RR/AFSDB.php Net/DNS2/RR/ANY.php \
		Net/DNS2/RR/APL.php Net/DNS2/RR/CERT.php Net/DNS2/RR/CNAME.php \
		Net/DNS2/RR/DHCID.php Net/DNS2/RR/DLV.php Net/DNS2/RR/DNAME.php \
		Net/DNS2/RR/DNSKEY.php Net/DNS2/RR/DS.php Net/DNS2/RR/EID.php \
		Net/DNS2/RR/HINFO.php Net/DNS2/RR/HIP.php Net/DNS2/RR/IPSECKEY.php \
		Net/DNS2/RR/ISDN.php Net/DNS2/RR/KEY.php Net/DNS2/RR/KX.php \
		Net/DNS2/RR/LOC.php Net/DNS2/RR/MX.php Net/DNS2/RR/NAPTR.php \
		Net/DNS2/RR/NIMLOC.php Net/DNS2/RR/NS.php Net/DNS2/RR/NSAP.php \
		Net/DNS2/RR/NSEC.php Net/DNS2/RR/NSEC3.php Net/DNS2/RR/NSEC3PARAM.php \
		Net/DNS2/RR/OPT.php Net/DNS2/RR/PTR.php Net/DNS2/RR/PX.php \
		Net/DNS2/RR/RP.php Net/DNS2/RR/RRSIG.php Net/DNS2/RR/RT.php \
		Net/DNS2/RR/SIG.php Net/DNS2/RR/SOA.php Net/DNS2/RR/SPF.php \
		Net/DNS2/RR/SRV.php Net/DNS2/RR/SSHFP.php Net/DNS2/RR/TKEY.php \
		Net/DNS2/RR/TSIG.php Net/DNS2/RR/TXT.php Net/DNS2/RR/X25.php \
		Net/DNS2/RR.php Net/DNS2/Resolver.php Net/DNS2/Socket/Sockets.php \
		Net/DNS2/Socket/Streams.php Net/DNS2/Socket.php Net/DNS2/Updater.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
