PORTNAME=	walker
PORTVERSION=	3.8
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/walker/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recover zone file information from servers that use DNSSEC
WWW=		https://josefsson.org/walker/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0:dns/p5-Net-DNS-SEC

USES=		perl5 shebangfix
SHEBANG_FILES=	walker
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/walker share/man/man1/walker.1.gz
PORTDOCS=	index.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/walker ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/walker.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
