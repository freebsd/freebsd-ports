# New ports collection makefile for:	Class-Tangram
# Date created:	   08 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Tangram
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Pod/Constants.pm:${PORTSDIR}/textproc/p5-Pod-Constants \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Tangram.pm:${PORTSDIR}/databases/p5-Tangram
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::Tangram.3

.include <bsd.port.mk>
