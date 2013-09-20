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

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/rbllookup
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rbl.pl ${PREFIX}/bin/rbllookup
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
