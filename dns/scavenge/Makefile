# Created by: mark@foster.cc
# $FreeBSD$

PORTNAME=	scavenge
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://mark.foster.cc/pub/scavenge/

MAINTAINER=	mark@foster.cc
COMMENT=	Discover/audit forward and reverse DNS records

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		nmap:${PORTSDIR}/security/nmap

NO_BUILD=	yes
USES=		perl5 shebangfix

PLIST_FILES=	bin/scavenge
SHEBANG_FILES=	src/scavenge

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/scavenge ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
