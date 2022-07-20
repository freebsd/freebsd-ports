PORTNAME=	LLnextgen
PORTVERSION=	0.5.5
CATEGORIES=	devel
MASTER_SITES=	https://os.ghalkes.nl/LLnextgen/releases/

MAINTAINER=	oleksii.tsai@gmail.com
COMMENT=	Extended LL(1) parser generator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LLnextgen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/LLnextgen.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README TODO Changelog doc/LLnextgen.pdf \
		doc/LLnextgen.ps.gz doc/calculator.g doc/threadsafe.g
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
