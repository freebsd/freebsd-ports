# ex:ts=8
# New ports collection makefile for:	p5-Exception-Class
# Date created:			Jul 28, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Exception-Class
PORTVERSION=	0.8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Exception
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Exception::Class.3

.include <bsd.port.mk>
