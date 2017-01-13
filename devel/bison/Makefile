# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	bison
PORTVERSION=	3.0.4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser generator from FSF, (mostly) compatible with Yacc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	m4>=1.4.16,1:devel/m4
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--disable-yacc
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_PERL5=	build
USES=		charsetfix localbase makeinfo perl5 tar:xz

INFO=		bison
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$$(docdir)\(/examples\)|$$(datarootdir)\1/bison|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/\(.*\) _Noreturn void/_Noreturn \1 void/' ${WRKSRC}/data/*.c ${WRKSRC}/lib/*.[ch]

.include <bsd.port.mk>
