# New ports collection makefile for:	zh-mplayer-fonts
# Date created:		17 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	mplayer-fonts
PORTVERSION=	1.0
CATEGORIES=	chinese multimedia
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/mplayer/
DISTFILES=	${SUBFONT_DISTNAME}.tar.bz2 \
		mplayer-fontmap-chinese.tar.bz2
EXTRACT_ONLY=	${SUBFONT_DISTNAME}.tar.bz2 mplayer-fontmap-chinese.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chinese font pack for the mplayer OSD and SUB

BUILD_DEPENDS=	${LOCALBASE}/lib/libiconv.so.3:${PORTSDIR}/converters/libiconv \
		${FREETYPE_CONFIG}:${PORTSDIR}/print/freetype2 \
		${ARPHIC_FONTDIR}/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		arial.ttf:${PORTSDIR}/x11-fonts/webfonts:build

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${SUBFONT_DISTNAME}
PLIST_SUB+=	MF=${MPLAYER_FONTDIR:S,${LOCALBASE}/,,g}

SUBFONT_DISTNAME=	subfont-c-0.90pre6
MPLAYER_FONTDIR=	${LOCALBASE}/share/mplayer/fonts/chinese
FREETYPE_CONFIG=	${LOCALBASE}/bin/freetype-config

ARPHIC_FONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
ARPHIC_FONTS_BIG5=	bkai00mp bsmi00lp
ARPHIC_FONTS_GB2312=	gbsn00lp gkai00mp
ALL_FONTS=		${ARPHIC_FONTS_BIG5} ${ARPHIC_FONTS_GB2312}
FONT_SIZES=		16 24
WEBFONTS_WRKSRC=	`cd ${PORTSDIR}/x11-fonts/webfonts/; make -V WRKSRC`

post-extract:
.for fn in ${ALL_FONTS}
	@${LN} -sf ${ARPHIC_FONTDIR}/${fn}.ttf ${WRKSRC}/
.endfor
	@${LN} -sf ${WRKDIR}/BIG5 ${WRKSRC}/encodings/
	@${LN} -sf ${WRKDIR}/GB2312 ${WRKSRC}/encodings/
	@${LN} -sf ${WEBFONTS_WRKSRC}/arial.ttf ${WRKSRC}/

pre-patch:
	@${ECHO_CMD} -e 'LDFLAGS=-lm `${FREETYPE_CONFIG} --libs` -liconv \
		-L${LOCALBASE}/lib\nCFLAGS=`${FREETYPE_CONFIG} --cflags` \
		-I${LOCALBASE}/include\nPROG=subfont\nNOMAN=yes\
		\n.include <bsd.prog.mk>' > ${WRKSRC}/Makefile

post-build:
.for font in ${ARPHIC_FONTS_BIG5}
.for size in ${FONT_SIZES}
	cd ${WRKSRC} && ${SH} runme-dbcs ${font} ${size} BIG5 2> /dev/null
.endfor
.endfor
.for font in ${ARPHIC_FONTS_GB2312}
.for size in ${FONT_SIZES}
	cd ${WRKSRC} && ${SH} runme-dbcs ${font} ${size} GB2312 2> /dev/null
.endfor
.endfor

do-install:
	@${MKDIR} ${MPLAYER_FONTDIR}
.for font in ${ALL_FONTS}
.for size in ${FONT_SIZES}
	@${TAR} -C ${WRKSRC} -cpf - ${font}${size} | \
	 ${TAR} -C ${MPLAYER_FONTDIR} -xpf -
.endfor
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
