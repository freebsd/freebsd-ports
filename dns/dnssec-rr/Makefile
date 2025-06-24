PORTNAME=	dnssec-rr
DISTVERSION=	0.2
CATEGORIES=	dns security
MASTER_SITES=	https://git.sr.ht/~mcf/dnssec-rr/refs/download/${DISTVERSION}/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Set of C programs for working with DNSSEC
WWW=		https://git.sr.ht/~mcf/dnssec-rr

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbearssl.so:security/bearssl

USES=		localbase:ldflags

PLIST_FILES=	bin/dnskey \
		bin/ds \
		bin/nsec \
		bin/rrsig \
		bin/tlsa \
		share/man/man1/dnskey.1.gz \
		share/man/man1/ds.1.gz \
		share/man/man1/nsec.1.gz \
		share/man/man1/rrsig.1.gz \
		share/man/man1/tlsa.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${MANDIRS}/man1
.for i in dnskey ds nsec rrsig tlsa
	${INSTALL_MAN} ${WRKSRC}/$i.1 \
		${STAGEDIR}${MANDIRS}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/$i \
		${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
