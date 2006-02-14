# New ports collection Makefile for:	p5-File-Remove
# Date created:				16th March 2001
# Whom: 				Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	File-Remove
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jus@security.za.net
COMMENT=	Perl5 module to easily removes files and directories

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	YES

MAN3=		File::Remove.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires File::Glob, which is only available in perl 5.6.0 or above
.endif

.include <bsd.port.post.mk>
