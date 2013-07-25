# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	sleuth
PORTVERSION=	1.4.4
CATEGORIES=	dns
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/mj/net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for checking DNS zones

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	yes
USES=		shebangfix
SHEBANG_FILES=	sleuth

PLIST_FILES=	bin/sleuth etc/sleuth.conf.sample

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/sleuth.conf|${PREFIX}/etc/sleuth.conf|' \
		${WRKSRC}/sleuth

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sleuth ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sleuth.conf ${PREFIX}/etc/sleuth.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
