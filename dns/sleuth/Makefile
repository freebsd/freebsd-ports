PORTNAME=	sleuth
DISTVERSION=	1.4.4
CATEGORIES=	dns
MASTER_SITES=	https://mj.ucw.cz/download/net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for checking, and diagnosing DNS zones

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		shebangfix perl5
SHEBANG_FILES=	sleuth

PLIST_FILES=	bin/sleuth etc/sleuth.conf.sample

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/sleuth.conf|${PREFIX}/etc/sleuth.conf|' \
		${WRKSRC}/sleuth

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sleuth ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sleuth.conf \
		${STAGEDIR}${PREFIX}/etc/sleuth.conf.sample

.include <bsd.port.mk>
