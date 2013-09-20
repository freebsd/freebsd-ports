# Created by: Jesper Dalberg <jesper@jdn.dk>
# $FreeBSD$

PORTNAME=	POE-Component-Server-XMLRPC
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@jdn.dk
COMMENT=	POE Component to create XMLRPC Servers

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Server-HTTP>=0:${PORTSDIR}/www/p5-POE-Component-Server-HTTP \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Component::Server::XMLRPC.3

NO_STAGE=	yes
.include <bsd.port.mk>
