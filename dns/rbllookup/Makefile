# Created by: Marcin Gondek <drixter@e-utp.net>
# $FreeBSD$

PORTNAME=	rbllookup
PORTVERSION=	0.0.1.1
PORTREVISION=	1
CATEGORIES=	dns mail
MASTER_SITES=	SF

MAINTAINER=	drixter@e-utp.net
COMMENT=	Check given IP/Host presence in 106 RBLs

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Term-ANSIColor>=0:devel/p5-Term-ANSIColor

USES=		perl5 shebangfix
SHEBANG_FILES=	rbl.pl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/rbllookup
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbl.pl ${STAGEDIR}${PREFIX}/bin/rbllookup
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
