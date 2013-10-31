# Created by: Koen Martens <gmc@sonologic.nl>
# $FreeBSD$

PORTNAME=	Net-DNS-Resolver-Programmable
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	gmc@sonologic.nl
COMMENT=	Programmable DNS resolver for off-line testing

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_STAGE=	yes
USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::DNS::Resolver::Programmable.3
PORTDOCS=	CHANGES README TODO
DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS-Resolver-Programmable

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
