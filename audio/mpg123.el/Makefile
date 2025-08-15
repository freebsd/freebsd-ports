PORTNAME=	mpg123.el
PORTVERSION=	1.65
PORTREVISION=	4
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	mpg123el.cgi?${PORTVERSION}
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Front-end to mpg123/ogg123 audio player for Emacsen
WWW=		http://www.gentei.org/~yuuji/software/mpg123el/

LICENSE=	BSD2CLAUSE

USES=		emacs

OPTIONS_SINGLE=		PLAYER
OPTIONS_SINGLE_PLAYER=	MPG123 MPLAYER
OPTIONS_DEFAULT=	MPLAYER
MPG123_DESC=		Use mpg123/ogg123 as audio player
MPLAYER_DESC=		Use mplayer as audio player
PLAYER_DESC=		Default audio player
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPG123_RUN_DEPENDS=	mpg123:audio/mpg123 \
			ogg123:audio/vorbis-tools
MPG123_EXTRA_PATCHES=	${FILESDIR}/extra-mpg123-patch-mpg123.el

CONFLICTS=	mpg123-emacs

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/mpg123.el

FETCH_ARGS=	-AR
FETCH_BEFORE_ARGS=	-o mpg123el.cgi?${PORTVERSION}

do-extract:
	${CP} ${DISTDIR}/mpg123el.cgi?${PORTVERSION} ${EXTRACT_WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
