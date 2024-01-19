PORTNAME=	mixal
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/mixal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assembler and interpreter for Donald Knuth's mythical MIX computer
WWW=		http://www.catb.org/~esr/mixal/

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mixal ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mixal.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in MIX.DOC NOTES README opcodes *.mix
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
