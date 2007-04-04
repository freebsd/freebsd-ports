# New ports collection makefile for:	p5-Error
# Date created:		24-May-2000
# Whom:	      		Peter van Heusden <pvh@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	Error
PORTVERSION=	0.17.008
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Error
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.(00[0-9])$/\1/}

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
