# Created by: fenner
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20121017
CATEGORIES=	dns ipv6
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	mark@foster.cc
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes

MAN8=		dnstop.8
PLIST_FILES=	bin/dnstop

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
