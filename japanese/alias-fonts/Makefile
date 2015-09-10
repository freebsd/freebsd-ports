# Created by: sada
# $FreeBSD$

PORTNAME=	alias-fonts
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Meta-port which setups Japanese fonts

RUN_DEPENDS=	ja-elisa8x8>0:${PORTSDIR}/japanese/elisa8x8 \
		ja-naga10>0:${PORTSDIR}/japanese/k10 \
		ja-font-shinonome>0:${PORTSDIR}/japanese/font-shinonome \
		ja-kanji18>0:${PORTSDIR}/japanese/kanji18 \
		ja-k20fonts>0:${PORTSDIR}/japanese/kappa20 \
		ja-kanji26>0:${PORTSDIR}/japanese/kanji26 \
		ja-font-jisx0213>0:${PORTSDIR}/japanese/font-jisx0213

NO_BUILD=	yes

USES=		fonts
PLIST_FILES=	%%FONTSDIR%%/fonts.alias
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
