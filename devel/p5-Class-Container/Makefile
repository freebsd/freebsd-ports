# New ports collection makefile for:	Class::Container
# Date created:				5 July 2002
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Container
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru

BUILD_DEPENDS=	${SITE_PERL}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Class::Container.3

.include <bsd.port.mk>
