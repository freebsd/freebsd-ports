# New ports collection makefile for:	Devel-Profile
# Date created:	   16 march 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Devel-Profile
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	m@absolight.net
COMMENT=	Tell me why my perl program runs so slowly

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Devel::Profile.3

.include <bsd.port.mk>
