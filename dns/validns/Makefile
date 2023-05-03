PORTNAME=	validns
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	High performance DNS/DNSSEC zone validator
WWW=		http://www.validns.net/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Last upstream release was 10 years ago and last upstream activity in 2017
EXPIRATION_DATE=	2023-06-03
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated RSA_* routines

LIB_DEPENDS=	libJudy.so:devel/judy
TEST_DEPENDS=	p5-Test-Command-Simple>=0:devel/p5-Test-Command-Simple

USES=		ssl

ALL_TARGET=	${PORTNAME}
TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
