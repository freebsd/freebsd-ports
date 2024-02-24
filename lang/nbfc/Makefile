PORTNAME=	nbfc
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://koeln.ccc.de/ablage/brainfuck/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	New Brainfuck Compiler
WWW=		https://koeln.ccc.de/ablage/brainfuck/index.en.xml

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/nbfc \
		share/man/man1/nbfc.1.gz

MAKE_ENV+=	FLEX=${FLEX} \
		YACC=${YACC} \
		STAGEDIR=${STAGEDIR}

MAKE_JOBS_UNSAFE=	yes

post-patch:
	# -O4 kills llvm
	${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|; s|O4|O3|g' \
	    ${WRKSRC}/config.h

.include <bsd.port.mk>
