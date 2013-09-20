# Created by: ijliao
# $FreeBSD$

PORTNAME=	walker
PORTVERSION=	3.8
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Recover zone file information from servers that use DNSSEC

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0:${PORTSDIR}/dns/p5-Net-DNS-SEC

USES=		perl5
NO_BUILD=	yes

MAN1=		walker.1
PLIST_FILES=	bin/walker
PORTDOCS=	index.html

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
