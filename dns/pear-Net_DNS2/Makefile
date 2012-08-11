# Ports collection makefile for:  pear-Net_DNS2
# Date created:		          Oct 27, 2010
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net_DNS2
PORTVERSION=	1.2.2
CATEGORIES=	dns net pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PHP5 Resolver library used to communicate with a DNS server

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Net
PEAR_CATSRC=	yes

FILES=		DNS2.php \
		DNS2/BitMap.php DNS2/Cache.php \
		DNS2/Cache/File.php DNS2/Cache/Shm.php \
		DNS2/Exception.php DNS2/Header.php \
		DNS2/Lookups.php \
		DNS2/Packet/Request.php DNS2/Packet/Response.php \
		DNS2/Packet.php DNS2/PrivateKey.php \
		DNS2/Question.php \
		DNS2/RR/A.php \
		DNS2/RR/AAAA.php DNS2/RR/AFSDB.php DNS2/RR/ANY.php \
		DNS2/RR/APL.php DNS2/RR/ATMA.php \
		DNS2/RR/CAA.php DNS2/RR/CDS.php \
		DNS2/RR/CERT.php DNS2/RR/CNAME.php \
		DNS2/RR/DHCID.php DNS2/RR/DLV.php DNS2/RR/DNAME.php \
		DNS2/RR/DNSKEY.php DNS2/RR/DS.php \
		DNS2/RR/EID.php \
		DNS2/RR/HINFO.php DNS2/RR/HIP.php DNS2/RR/IPSECKEY.php \
		DNS2/RR/ISDN.php DNS2/RR/KEY.php DNS2/RR/KX.php \
		DNS2/RR/LOC.php DNS2/RR/MX.php DNS2/RR/NAPTR.php \
		DNS2/RR/NIMLOC.php DNS2/RR/NS.php DNS2/RR/NSAP.php \
		DNS2/RR/NSEC.php DNS2/RR/NSEC3.php DNS2/RR/NSEC3PARAM.php \
		DNS2/RR/OPT.php DNS2/RR/PTR.php DNS2/RR/PX.php \
		DNS2/RR/RP.php DNS2/RR/RRSIG.php DNS2/RR/RT.php \
		DNS2/RR/SIG.php DNS2/RR/SOA.php DNS2/RR/SPF.php \
		DNS2/RR/SRV.php DNS2/RR/SSHFP.php \
		DNS2/RR/TA.php DNS2/RR/TALINK.php DNS2/RR/TKEY.php \
		DNS2/RR/TSIG.php DNS2/RR/TXT.php \
		DNS2/RR/URI.php DNS2/RR/WKS.php \
		DNS2/RR/X25.php \
		DNS2/RR.php DNS2/Resolver.php DNS2/Socket/Sockets.php \
		DNS2/Socket/Streams.php DNS2/Socket.php DNS2/Updater.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
