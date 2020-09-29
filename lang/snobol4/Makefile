# Created by: Wes Peters <wes@softweyr.com>
# $FreeBSD$

PORTNAME=	snobol4
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ultimate.com/snobol/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Macro SNOBOL4, supports full SNOBOL4 plus SPITBOL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${PATCHDIR}/LICENSE

USES=		gmake libedit
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--snolibdir=${PREFIX}/lib/${PORTNAME}
CONFIGURE_ENV+=	DL_EXT=".so"
ALL_TARGET=	xsnobol4
LDFLAGS+=	-L${PREFIX}/lib

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PLIST_SUB+=	VERSION=${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS


post-patch:
	@${REINPLACE_CMD} 's:[^=]*\.tmp$$:${WRKSRC}/&:' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's:../snobol4:../xsnobol4:' \
		${WRKSRC}/doc/Makefile ${WRKSRC}/modules/*/Makefile
	@${REINPLACE_CMD} -e 's:<BINDIR>:${PREFIX}/bin:' \
		-e 's:<SNOLIB_LIB>:${PREFIX}/lib/${PORTNAME}:' \
		${WRKSRC}/snopea.in ${WRKSRC}/sdb.sh

.include <bsd.port.mk>
