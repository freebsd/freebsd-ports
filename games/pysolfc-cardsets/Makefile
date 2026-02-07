PORTNAME=	pysolfc-cardsets
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/pysolfc/PySolFC-Cardsets/PySolFC-Cardsets-${PORTVERSION}/ \
		https://slackware.uk/~urchlay/src/:bk
DISTNAME=	PySolFC-Cardsets-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2 \
		pysolfc-cardsets-bknoll.tar.xz:bk

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of free cardsets adapted for use with PySolFC
WWW=		https://pysolfc.sourceforge.io/

LICENSE=	GPLv2+

RUN_DEPENDS=	pysolfc:games/pysolfc

NO_ARCH=	yes
NO_BUILD=	yes

post-extract:
	@${RM} -r ${WRKSRC}/.fr-KuTbSg
# Remove cardsets which are bundled with PySolFC main distribution
.for set in 2000 blaren-7x7 crystal-mahjongg dashavatara-ganjifa \
    dashavatara-ganjifa-xl dojouji-3x3 dondorf gnome-mahjongg-1 \
    hanafuda-200-years hexadeck hokusai-6x6 knave-of-hearts-4x4 \
    louie-mantia-hanafuda matching matching-xl matrix mid-winter-eve-8x8 \
    mughal-ganjifa mughal-ganjifa-xl neo neo-hex neo-tarock next-matrix \
    oxymoron players-trumps-10x10 simple-ishido simple-ishido-xl standard \
    the-card-players-9x9 tuxedo uni-mahjongg victoria-falls-5x5 vienna-2k
	@${RM} -r ${WRKSRC}/cardset-${set}
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/PySolFC
	cd ${WRKSRC}/../pysolfc-cardsets-bknoll && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/PySolFC

.include <bsd.port.mk>
