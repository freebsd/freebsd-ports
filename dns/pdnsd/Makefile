# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	pdnsd
PORTVERSION=	1.2.9a
CATEGORIES=	dns
MASTER_SITES=	http://members.home.nl/p.a.rombouts/pdnsd/releases/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}-par

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Caching (permanently, writes to disk on exit) DNS proxy-server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	pdnsd
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB} \
		--disable-src-addr-disc

OPTIONS_DEFINE=	IPV6 DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PDNSDB=		/var/db/pdnsd
DOCSRCDIR=	${WRKSRC}/doc
DOC_FILES=	html/dl.html html/doc.html html/faq.html html/index.html
DOC_FILES+=	txt/faq.txt txt/intro.txt txt/manual.txt

CFLAGS+=	-pthread

IPV6_CONFIGURE_ENABLE=	ipv6

post-install:
	@${RM} ${STAGEDIR}${PDNSDB}/pdnsd.cache

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DOC_FILES:S@^@${DOCSRCDIR}/@} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
