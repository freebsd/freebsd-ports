# New ports collection makefile for:	POE-Component-IRC
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC
PORTVERSION=	1.7
CATEGORIES=	devel perl5 irc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::Filter-CTCP.3 POE::Component::Filter-IRC.3 \
		POE::Component::IRC.3
MLINKS=		POE::Component::Filter-CTCP.3 POE::Component::Filter::CTCP.3 \
		POE::Component::Filter-IRC.3 POE::Component::Filter::IRC.3

post-install:
.ifndef(NOPORTDOCS)
		@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
