# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	bison
PORTVERSION=	3.5.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parser generator from FSF, (mostly) compatible with Yacc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	m4>=1.4.16,1:devel/m4

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

USES=		charsetfix compiler:c11 localbase makeinfo perl5 tar:xz
USE_PERL5=	build

CONFIGURE_ARGS=	--disable-yacc --enable-relocatable
GNU_CONFIGURE=	yes
LIBS+=		-lm
TEST_TARGET=	check

INFO=		bison

NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_OFF=	ac_cv_libtextstyle=no
NLS_LIB_DEPENDS=	libtextstyle.so:devel/libtextstyle
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$$(docdir)\(/examples\)|$$(datarootdir)\1/bison|' ${WRKSRC}/Makefile.in
	@${GREP} -l '_Noreturn void' ${WRKSRC}/lib/*.[ch] | ${XARGS} -J % ${REINPLACE_CMD} -e 's|\(.*\) _Noreturn void|_Noreturn \1 void|' %

.include <bsd.port.mk>
