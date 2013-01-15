# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline-CPP
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in C++

LICENSE=	ART10

RUN_DEPENDS=	p5-Inline>=0.51:${PORTSDIR}/devel/p5-Inline \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

PERL_CONFIGURE=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
EXTRA_PATCHES+=	${FILESDIR}/opt-patch-Makefile.PL
.else
IS_INTERACTIVE=	yes
.endif

MAN3=		Inline::CPP.3 \
		Inline::CPP::Config.3 \
		Inline::CPP::grammar.3

post-patch:
	@${REINPLACE_CMD} -e 's/g++/${CXX}/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
