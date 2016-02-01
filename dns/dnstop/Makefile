# Created by: fenner
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20140915
CATEGORIES=	dns ipv6
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	mark@foster.cc
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)

LICENSE=	BSD2CLAUSE

USES=		ncurses
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dnstop \
		man/man8/dnstop.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
