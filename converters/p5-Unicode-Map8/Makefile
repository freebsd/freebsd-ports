# New ports collection makefile for:	p5-Unicode-Map8
# Date created:				20 September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$

PORTNAME=	Unicode-Map8
PORTVERSION=	0.10
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su

BUILD_DEPENDS=	${SITE_PERL}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}
PERL_CONFIGURE=	yes

MAN3=		Unicode::Map8.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
