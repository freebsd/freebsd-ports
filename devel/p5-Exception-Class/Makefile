# ex:ts=8
# New ports collection makefile for:	p5-Exception-Class
# Date created:			Jul 28, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Exception-Class
PORTVERSION=	1.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Exception
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Exception::Class.3

.include <bsd.port.mk>
