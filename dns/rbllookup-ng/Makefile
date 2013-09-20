# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	rbllookup-ng
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	dns mail
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Check given IP/Host presence in RBLs

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/rbllookup bin/getmoensted etc/rbllookup.conf-sample
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

CONFLICTS=	rbllookup-0.*

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/rbllookup.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbllookup.pl ${PREFIX}/bin/rbllookup
	${INSTALL_SCRIPT} ${WRKSRC}/getmoensted.pl ${PREFIX}/bin/getmoensted
	${INSTALL_DATA} ${WRKSRC}/rbllookup.conf ${PREFIX}/etc/rbllookup.conf-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
