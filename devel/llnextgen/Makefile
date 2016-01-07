# Created by: Oleksii Tsai <oleksii.tsai@gmail.com>
# $FreeBSD$

PORTNAME=	LLnextgen
PORTVERSION=	0.5.5
CATEGORIES=	devel
MASTER_SITES=	http://os.ghalkes.nl/LLnextgen/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oleksii.tsai@gmail.com
COMMENT=	Extended LL(1) parser generator

LICENSE=	GPLv3

HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LLnextgen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/LLnextgen.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README COPYING TODO Changelog doc/LLnextgen.pdf \
		doc/LLnextgen.ps.gz doc/calculator.g doc/threadsafe.g
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
