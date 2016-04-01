# Created by: ijliao
# $FreeBSD$

PORTNAME=	AI-Prolog
PORTVERSION=	0.741
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOUGW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for logic programming

RUN_DEPENDS=	p5-aliased>=0.11:devel/p5-aliased \
		p5-Clone>=0.15:devel/p5-Clone \
		p5-Exporter-Tidy>=0.06:devel/p5-Exporter-Tidy \
		p5-Hash-AsObject>=0.05:devel/p5-Hash-AsObject \
		p5-Regexp-Common>=2.119:textproc/p5-Regexp-Common \
		p5-Text-Quote>=0.03:textproc/p5-Text-Quote \
		p5-Term-ReadKey>=2.21:devel/p5-Term-ReadKey
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=</dev/null

.include <bsd.port.mk>
