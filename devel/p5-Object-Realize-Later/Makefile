# New ports collection makefile for:	Object-Realize-Later
# Date created:				05 Mar 2003
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Object-Realize-Later
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Object
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object::Realize::Later - Delayed creation of objects

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

MAN3=		Object::Realize::Later.3

.include <bsd.port.post.mk>
