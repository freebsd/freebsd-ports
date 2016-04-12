# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	File-ShareDir-PAR
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl5 File::ShareDir module with PAR support

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-PAR>=0:devel/p5-PAR \
		p5-Params-Util>=0:devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
