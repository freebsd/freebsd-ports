# New ports collection makefile for:	p5-Error
# Date created:		24-May-2000
# Whom:	      		Peter van Heusden <pvh@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	Error
PORTVERSION=	0.17.004
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Error
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.17004

MAINTAINER=	pvh@wfeet.za.net
COMMENT=	Perl module to provide Error/exception support for perl: Error

PERL_CONFIGURE=	YES

MAN3=		Error.3 Error::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500702
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
