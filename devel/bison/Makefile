# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	bison
PORTVERSION=	2.7.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Parser generator from FSF, (mostly) compatible with Yacc

BUILD_DEPENDS=	m4>=1.4.16,1:devel/m4
RUN_DEPENDS=	m4>=1.4.16,1:devel/m4

OPTIONS_DEFINE=	EXAMPLES NLS

USES=		charsetfix makeinfo perl5 tar:xz
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-yacc

INFO=		bison

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*
	@${REINPLACE_CMD} 's/MANS = yacc.1/MANS =/' ${WRKSRC}/doc/Makefile.in

PORTEXAMPLES=	calc++

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/calc++
	${INSTALL_DATA} ${WRKSRC}/examples/calc++/*.[chly]* \
		${STAGEDIR}${EXAMPLESDIR}/calc++

.include <bsd.port.mk>
