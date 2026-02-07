PORTNAME=	hp48cc
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	SUNSITE/devel/lang/c \
		http://www.sigala.it/sandro/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C-like compiler that translates input code to the HP48 RPL language
WWW=		http://www.sigala.it/sandro/software.php #hp48cc

LICENSE=	GPLv2

USES=		bison
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
# Fix the Makefile to unbreak parallel builds
	@${REINPLACE_CMD} -e 's,(YACC),& -o parser.c, ; \
		s,(LEX),& -olexer.c, ; /mv/d' ${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
