# New ports collection makefile for:	Params::Validate
# Date created:				10 April 2001
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	Params-Validate
PORTVERSION=	0.54
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	Validate method/function parameters

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		Attribute::Params::Validate.3 Params::ValidateXS.3 \
		Params::ValidatePP.3 Params::Validate.3

.include <bsd.port.pre.mk>

##
## this port depends on devel/p5-Attribute-Handlers
## which requires PERL 5.6.x or later
##
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
