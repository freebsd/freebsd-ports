# New ports collection makefile for:	POE-Component-Server-XMLRPC
# Date created:		14 Jun 2004
# Whom:			Jesper Dalberg <jesper@jdn.dk>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-XMLRPC
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@jdn.dk
COMMENT=	POE Component to create XMLRPC Servers

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/Server/HTTP.pm:${PORTSDIR}/www/p5-POE-Component-Server-HTTP \
		${SITE_PERL}/XMLRPC/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::XMLRPC.3

.include <bsd.port.mk>
