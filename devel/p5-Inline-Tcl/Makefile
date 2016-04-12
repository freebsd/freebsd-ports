# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline-Tcl
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5 tcl
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines in Tcl

LICENSE=	ARTPERL10

BUILD_DEPENDS=	p5-Inline>=0:devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tcl
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${TCL_INCLUDEDIR}" \
		LIBS="-L${TCL_LIBDIR} -Wl,-rpath,${TCL_LIBDIR} -ltcl${TCL_SHLIB_VER}"

post-patch:
	@${REINPLACE_CMD} '2,99d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
