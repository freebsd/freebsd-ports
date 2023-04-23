PORTNAME=	pysolfc-cardsets
PORTVERSION=	2.2
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
# Remove cardsets which are bundled with PySolFC main distribution
.for set in 2000 crystal-mahjongg dondorf dashavatara-ganjifa-xl \
    dashavatara-ganjifa gnome-mahjongg-1 hanafuda-200-years hexadeck \
    louie-mantia-hanafuda matching matching-xl matrix mughal-ganjifa \
    mughal-ganjifa-xl neo neo-hex neo-tarock next-matrix oxymoron \
    standard tuxedo uni-mahjongg vienna-2k
	@${RM} -r ${WRKSRC}/cardset-${set}
.endfor
# Garbage-collect temporary cache files created by image viewers
.for set in gdkcard-bonded fine-art-tarot konqi-modern nicu-small \
    warwick xpat2-nox-large
	@${RM} -r ${WRKSRC}/cardset-${set}/.thumbnails \
		  ${WRKSRC}/cardset-${set}/.xvpics
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/PySolFC
	cd ${WRKSRC}/../pysolfc-cardsets-bknoll && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/PySolFC

.include <bsd.port.mk>
