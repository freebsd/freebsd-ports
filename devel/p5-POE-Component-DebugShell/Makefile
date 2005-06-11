# New ports collection makefile for:	POE-Component-DebugShell
# Date created:	   28 February 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-DebugShell
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Interactive peeking into a running POE application

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/API/Peek.pm:${PORTSDIR}/devel/p5-POE-API-Peek
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		POE::Component::DebugShell.3

post-patch:
	${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	${PERL} -pi -e 's/^auto_install.*//;' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	Perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
