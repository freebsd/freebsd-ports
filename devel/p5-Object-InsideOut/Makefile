# New ports collection makefile for:	devel/p5-Object-InsideOut
# Date created:				15 January 2006
# Whom:					Geraud Continsouzas <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	Object-InsideOut
PORTVERSION=	1.42
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Object
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Object::InsideOut - Comprehensive inside-out object support module

BUILD_DEPENDS=	p5-Exception-Class>=1.22:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Test-Simple>=0.50:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Object::InsideOut.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
