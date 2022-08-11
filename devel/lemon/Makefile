PORTNAME=	lemon
PORTVERSION=	3.34
CATEGORIES=	devel
MASTER_SITES=	http://tx97.net/pub/distfiles/ \
		https://bsdforge.com/projects/source/devel/lemon/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	LALR(1) parser generator. Similar in function to yacc and bison

LICENSE=	PD

USES=	tar:bzip2
MAKEFILE=	/dev/null
ALL_TARGET=	${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|toFree = tpltname = pathsearch(.*|tpltname = "${DATADIR}/lempar.c";|' \
		${WRKSRC}/lemon.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemon ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lempar.c ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
