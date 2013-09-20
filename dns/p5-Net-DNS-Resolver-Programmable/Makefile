# Created by: Koen Martens <gmc@sonologic.nl>
# $FreeBSD$

PORTNAME=	Net-DNS-Resolver-Programmable
PORTVERSION=	0.003
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	gmc@sonologic.nl
COMMENT=	Programmable DNS resolver for off-line testing

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-version>=0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::DNS::Resolver::Programmable.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PORTDOCS=	CHANGES README TODO
DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS-Resolver-Programmable

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
