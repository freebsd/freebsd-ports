# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	rbllookup-ng
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	dns mail
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check given IP/Host presence in RBLs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		perl5 shebangfix
SHEBANG_FILES=	rbllookup.pl getmoensted.pl
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/rbllookup bin/getmoensted "@sample etc/rbllookup.conf.sample"
PORTDOCS=	CHANGELOG INSTALL NOTES README TODO gpg.asc

CONFLICTS=	rbllookup-0.*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/rbllookup.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbllookup.pl \
		${STAGEDIR}${PREFIX}/bin/rbllookup
	${INSTALL_SCRIPT} ${WRKSRC}/getmoensted.pl \
		${STAGEDIR}${PREFIX}/bin/getmoensted
	${INSTALL_DATA} ${WRKSRC}/rbllookup.conf \
		${STAGEDIR}${PREFIX}/etc/rbllookup.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
