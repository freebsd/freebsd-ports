# New ports collection makefile for:	POE-Component-RSS
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-RSS
PORTVERSION=	0.06
CATEGORIES=	devel perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::RSS.3

.include <bsd.port.mk>
