# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Assets
PORTVERSION=	0.064
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RKRIMEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module to Manage .css and .js assets

BUILD_DEPENDS=	p5-Test-Memory-Cycle>0:devel/p5-Test-Memory-Cycle \
	p5-Directory-Scratch>0:devel/p5-Directory-Scratch \
	p5-MIME-Types>0:mail/p5-MIME-Types \
	p5-Path-Resource>0:devel/p5-Path-Resource \
	p5-Tie-LLHash>0:devel/p5-Tie-LLHash \
	p5-Carp-Clan-Share>0:devel/p5-Carp-Clan-Share \
	p5-Object-Tiny>0:devel/p5-Object-Tiny \
	p5-HTML-Declare>0:www/p5-HTML-Declare \
	p5-XML-Tiny>0:textproc/p5-XML-Tiny \
	p5-IO-Stringy>0:devel/p5-IO-Stringy \
	p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
	p5-JavaScript-Minifier-XS>=0:textproc/p5-JavaScript-Minifier-XS
RUN_DEPENDS=	p5-Test-Memory-Cycle>0:devel/p5-Test-Memory-Cycle \
	p5-Directory-Scratch>0:devel/p5-Directory-Scratch \
	p5-MIME-Types>0:mail/p5-MIME-Types \
	p5-Path-Resource>0:devel/p5-Path-Resource \
	p5-Tie-LLHash>0:devel/p5-Tie-LLHash \
	p5-Carp-Clan-Share>0:devel/p5-Carp-Clan-Share \
	p5-Object-Tiny>0:devel/p5-Object-Tiny \
	p5-HTML-Declare>0:www/p5-HTML-Declare \
	p5-XML-Tiny>0:textproc/p5-XML-Tiny \
	p5-IO-Stringy>0:devel/p5-IO-Stringy \
	p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
	p5-JavaScript-Minifier-XS>=0:textproc/p5-JavaScript-Minifier-XS

USES=		perl5
USE_PERL5=	configure

PORTSCOUT=	skipv:0.064_1

.include <bsd.port.mk>
