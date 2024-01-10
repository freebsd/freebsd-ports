PORTNAME=	dnstop
PORTVERSION=	20140915
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	mark@foster.cc
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)
WWW=		http://dnstop.measurement-factory.com/

LICENSE=	BSD2CLAUSE

USES=		ncurses
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dnstop \
		share/man/man8/dnstop.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
