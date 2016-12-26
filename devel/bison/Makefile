# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	bison
PORTVERSION=	2.7.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser generator from FSF, (mostly) compatible with Yacc

BUILD_DEPENDS=	m4>=1.4.16,1:devel/m4
RUN_DEPENDS=	m4>=1.4.16,1:devel/m4

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

CONFIGURE_ARGS+=--disable-yacc
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
TEST_TARGET=	check
USE_PERL5=	build
USES=		charsetfix makeinfo perl5 tar:xz

INFO=		bison
PORTEXAMPLES=	calc++

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${RM} ${WRKSRC}/doc/bison.info*
	@${REINPLACE_CMD} 's/MANS = yacc.1/MANS =/' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/calc++
	${INSTALL_DATA} ${WRKSRC}/examples/calc++/*.[chly]* ${STAGEDIR}${EXAMPLESDIR}/calc++

.include <bsd.port.mk>
