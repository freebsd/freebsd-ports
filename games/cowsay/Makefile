# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cowsay
PORTVERSION=	3.03
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/lifanov-ports-distfiles/${CATEGORIES}/${PORTNAME}

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Configurable talking characters in ASCII art

USES=		perl5

NO_BUILD=	# defined

post-patch:
	@${REINPLACE_CMD} 's,usethisperl=.*,usethisperl=${PERL},' ${WRKSRC}/install.sh

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${STAGEDIR}${PREFIX}
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/cowsay
	@${INSTALL_DATA} ${FILESDIR}/box.cow ${STAGEDIR}${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/jkh.cow ${STAGEDIR}${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/tux-stab.cow ${STAGEDIR}${PREFIX}/share/cows

.include <bsd.port.mk>
