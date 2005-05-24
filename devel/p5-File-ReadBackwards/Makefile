# New ports collection makefile for:	devel/p5-File-ReadBackwards
# Date created:				11 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	File-ReadBackwards
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	File::ReadBackwards -- read a file backwards by lines

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3=		File::ReadBackwards.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or newer"
.endif

.include <bsd.port.post.mk>
