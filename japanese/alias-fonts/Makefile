# Created by: sada
# $FreeBSD$

PORTNAME=	alias-fonts
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Meta-port which setups Japanese fonts

RUN_DEPENDS=	ja-font-elisa8>0:japanese/font-elisa8 \
		ja-font-naga10>0:japanese/font-naga10 \
		ja-font-shinonome>0:japanese/font-shinonome \
		ja-font-kanji18>0:japanese/font-kanji18 \
		ja-font-kappa20>0:japanese/font-kappa20 \
		ja-font-kanji26>0:japanese/font-kanji26 \
		ja-font-jisx0213>0:japanese/font-jisx0213

NO_BUILD=	yes

USES=		fonts
PLIST_FILES=	%%FONTSDIR%%/fonts.alias
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
