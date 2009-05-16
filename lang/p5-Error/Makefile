# New ports collection makefile for:	p5-Error
# Date created:		24-May-2000
# Whom:	      		Peter van Heusden <pvh@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	Error
PORTVERSION=	0.17015
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Perl module to provide Error/exception support for perl: Error

PERL_CONFIGURE=	YES

MAN3=		Error.3 Error::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils

MAKE_JOBS_SAFE=  yes
.endif

.include <bsd.port.post.mk>
