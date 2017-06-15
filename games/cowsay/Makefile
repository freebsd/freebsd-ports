# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cowsay
PORTVERSION=	3.04
DISTVERSIONPREFIX=	cowsay-
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Configurable talking characters in ASCII art

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5

USE_GITHUB=	yes

GH_ACCOUNT=	tnalpgge
GH_PROJECT=	rank-amateur-cowsay

NO_BUILD=	# defined

post-patch:
	@${REINPLACE_CMD} 's,usethisperl=.*,usethisperl=${PERL},' ${WRKSRC}/install.sh

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${STAGEDIR}${PREFIX}
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/cowsay
	${INSTALL_DATA} ${FILESDIR}/box.cow ${STAGEDIR}${PREFIX}/share/cows
	${INSTALL_DATA} ${FILESDIR}/jkh.cow ${STAGEDIR}${PREFIX}/share/cows
	${INSTALL_DATA} ${FILESDIR}/tux-stab.cow ${STAGEDIR}${PREFIX}/share/cows

.include <bsd.port.mk>
