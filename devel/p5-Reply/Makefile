# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Reply
PORTVERSION=	0.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight, extensible REPL for Perl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Config-INI-Reader-Ordered>=0:devel/p5-Config-INI-Reader-Ordered \
		p5-Devel-LexAlias>=0:devel/p5-Devel-LexAlias \
		p5-Eval-Closure>=0.11:devel/p5-Eval-Closure \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Package-Stash>=0:devel/p5-Package-Stash \
		p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
