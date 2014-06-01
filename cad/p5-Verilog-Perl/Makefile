# Created by: Otacilio de Araujo Ramos Neto <otacilio.neto@ee.ufcg.edu.br>
# $FreeBSD$

PORTNAME=	Verilog-Perl
PORTVERSION=	3.400
CATEGORIES=	cad perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	otacilio.neto@ee.ufcg.edu.br
COMMENT=	Building point for Verilog support in the Perl language

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex

USES=		bison gmake perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/ s/ vsplitmodule//' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|make|gmake|g' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Verilog/Parser/*.so

regression-test: build
	make test -C ${WRKSRC}

.include <bsd.port.post.mk>
