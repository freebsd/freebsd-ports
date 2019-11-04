# Created by: Wes Peters <wes@softweyr.com>
# $FreeBSD$

PORTNAME=	snobol4
PORTVERSION=	2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ultimate.com/snobol/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Macro SNOBOL4, supports full SNOBOL4 plus SPITBOL

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--snolibdir=${PREFIX}/lib/${PORTNAME}
CONFIGURE_ENV+=	DL_EXT=".so"
USES=		gmake
PLIST_SUB+=	VERSION=${PORTVERSION}
ALL_TARGET=	xsnobol4

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's:[^=]*\.tmp$$:${WRKSRC}/&:' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/grep/s/$$/| egrep -v "built-in|command line"/' \
		${WRKSRC}/cc-M
	@${REINPLACE_CMD} 's:../snobol4:../xsnobol4:' \
		${WRKSRC}/doc/Makefile ${WRKSRC}/modules/*/Makefile
	@${REINPLACE_CMD} -e 's:<BINDIR>:${PREFIX}/bin:' \
		-e 's:<SNOLIB_LIB>:${PREFIX}/lib/${PORTNAME}:' \
		${WRKSRC}/snopea.in ${WRKSRC}/sdb.sh

.include <bsd.port.mk>
