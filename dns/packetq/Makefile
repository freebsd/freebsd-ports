PORTNAME=	packetq
DISTVERSION=	1.7.3
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/packetq/

MAINTAINER=	freebsd@dns.company
COMMENT=	Basic SQL-frontend to PCAP-files
WWW=		https://www.dns-oarc.net/tools/packetq

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/packetq
PORTDOCS=	CHANGES COPYING FAQ.md FIELDS.md FUNCTIONS.md README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
