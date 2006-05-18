# New ports collection makefile for:	Class-Gomor
# Date created:				17 May 2006
# Whom:					Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		Class-Gomor
PORTVERSION=		1.00
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=		p5-

MAINTAINER=		boumenot@gmail.com
COMMENT=		Class and object builder

PERL_CONFIGURE=	yes

MAN3=	Class::Gomor.3 \
	Class::Gomor::Hash.3 \
	Class::Gomor::Array.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=Needs perl 5.6.0 or higher, install lang/perl5.6 and try again.
.endif

.include <bsd.port.post.mk>
