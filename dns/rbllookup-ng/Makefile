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
USES=		perl5 shebangfix

PLIST_FILES=	bin/rbllookup bin/getmoensted etc/rbllookup.conf-sample
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc
SHEBANG_FILES=	rbllookup.pl

CONFLICTS=	rbllookup-0.*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbllookup.pl \
		${STAGEDIR}${PREFIX}/bin/rbllookup
	${INSTALL_SCRIPT} ${WRKSRC}/getmoensted.pl \
		${STAGEDIR}${PREFIX}/bin/getmoensted
	${INSTALL_DATA} ${WRKSRC}/rbllookup.conf \
		${STAGEDIR}${PREFIX}/etc/rbllookup.conf-sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
