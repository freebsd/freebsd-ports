# Created by: Marcin Gondek <drixter@e-utp.net>
# $FreeBSD$

PORTNAME=	rbllookup
PORTVERSION=	0.0.1.1
CATEGORIES=	dns mail
MASTER_SITES=	SF

MAINTAINER=	drixter@e-utp.net
COMMENT=	Check given IP/Host presence in 106 RBLs

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/rbllookup
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rbl.pl ${STAGEDIR}${PREFIX}/bin/rbllookup
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
