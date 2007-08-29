# New ports collection makefile for:	p5-Error
# Date created:		24-May-2000
# Whom:	      		Peter van Heusden <pvh@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	Error
PORTVERSION=	0.17.009
DISTVERSION=	${PORTVERSION:C/\.(...)$/\1/}
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to provide Error/exception support for perl: Error

BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Error.3 Error::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500702
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
