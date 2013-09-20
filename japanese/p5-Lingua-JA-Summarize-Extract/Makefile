# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Lingua-JA-Summarize-Extract
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	Summary generator for Japanese

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::JA::Summarize::Extract::Plugin::Sentence::Base.3 \
		Lingua::JA::Summarize::Extract::Plugin::Parser::Ngram.3 \
		Lingua::JA::Summarize::Extract::Plugin::Parser::Trim.3 \
		Lingua::JA::Summarize::Extract.3 \
		Lingua::JA::Summarize::Extract::Plugin::Parser::NgramSimple.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
