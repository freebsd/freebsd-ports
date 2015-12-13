# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cowsay
PORTVERSION=	3.03
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.nog.net/~tony/warez/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Configurable talking characters in ASCII art

BROKEN=		unfetchable
USES=		perl5

NO_BUILD=	# defined

.if defined(MAINTAINER_MODE)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}.sig
verify: fetch
	@${ECHO_MSG} "Checking ${DISTNAME}${EXTRACT_SUFX}"
	@gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig 2>/dev/null || echo "Bad signature!"
	@${ECHO_MSG} "Done"
.endif

post-patch:
	@${REINPLACE_CMD} 's,usethisperl=.*,usethisperl=${PERL},' ${WRKSRC}/install.sh

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${STAGEDIR}${PREFIX}
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/cowsay
	@${INSTALL_DATA} ${FILESDIR}/box.cow ${STAGEDIR}${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/jkh.cow ${STAGEDIR}${PREFIX}/share/cows
	@${INSTALL_DATA} ${FILESDIR}/tux-stab.cow ${STAGEDIR}${PREFIX}/share/cows

.include <bsd.port.mk>
