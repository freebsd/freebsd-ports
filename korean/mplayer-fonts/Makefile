# New ports collection makefile for:	ko-mplayer-fonts
# Date created:		17 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	mplayer-fonts
PORTVERSION=	1.0
CATEGORIES=	korean graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/ \
		http://www.yonsei.ac.kr/yu/intro/symbol/:yonsei
MASTER_SITE_SUBDIR=	perky
DISTFILES=	${SUBFONT_DISTNAME}.tar.bz2 \
		mplayer-fontmap-euc-kr.tar.bz2 \
		${YONSEI_TITLE_DISTNAME}:yonsei \
		${YONSEI_TEXT_DISTNAME}:yonsei
EXTRACT_ONLY=	${SUBFONT_DISTNAME}.tar.bz2 mplayer-fontmap-euc-kr.tar.bz2

MAINTAINER=	perky@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libiconv.so.3:${PORTSDIR}/converters/libiconv \
		${FREETYPE_CONFIG}:${PORTSDIR}/print/freetype2 \
		${BAEKMUK_FONTDIR}/gulim.ttf:${PORTSDIR}/korean/baekmukfonts-ttf

USE_BZIP2=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${SUBFONT_DISTNAME}
PLIST_SUB+=	MF=${MPLAYER_FONTDIR:S,${LOCALBASE}/,,g}

SUBFONT_DISTNAME=	subfont-c-0.90pre6
MPLAYER_FONTDIR=	${LOCALBASE}/share/mplayer/fonts/korean
FREETYPE_CONFIG=	${LOCALBASE}/bin/freetype-config

BAEKMUK_FONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
BAEKMUK_FONTS=		gulim dotum batang
YONSEI_TITLE_DISTNAME=	%BF%AC%BC%BC%C1%A6%B8%F1.TTF
YONSEI_TEXT_DISTNAME=	%BF%AC%BC%BC%BA%BB%B9%AE.TTF
YONSEI_TITLE_FONTNAME=	YonseiTitle
YONSEI_TEXT_FONTNAME=	YonseiText
ALL_FONTS=		${BAEKMUK_FONTS} ${YONSEI_TITLE_FONTNAME} \
			${YONSEI_TEXT_FONTNAME}
FONT_SIZES=		12 16 20 24

post-extract:
	@${LN} -sf ${DISTDIR}/${YONSEI_TITLE_DISTNAME} \
		${WRKSRC}/${YONSEI_TITLE_FONTNAME}.ttf
	@${LN} -sf ${DISTDIR}/${YONSEI_TEXT_DISTNAME} \
		${WRKSRC}/${YONSEI_TEXT_FONTNAME}.ttf
.for fn in ${BAEKMUK_FONTS}
	@${LN} -sf ${BAEKMUK_FONTDIR}/${fn}.ttf ${WRKSRC}/
.endfor
	@${LN} -sf ${WRKDIR}/euc-kr ${WRKSRC}/

post-patch:
	@${ECHO_CMD} -e 'LDFLAGS=-lm `${FREETYPE_CONFIG} --libs` -liconv \
		-L${LOCALBASE}/lib\nCFLAGS=`${FREETYPE_CONFIG} --cflags` \
		-I${LOCALBASE}/include\nPROG=subfont\nNOMAN=yes\
		\n.include <bsd.prog.mk>' > ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,^encoding.*,encoding=euc-kr,;\
		s,^fontsize.*,fontsize=\$$3,;\
		s,^symbolssize.*,symbolssize=\$$((\$$fontsize-2)),' \
		${WRKSRC}/fontgen

post-build:
.for font in ${ALL_FONTS}
.for size in ${FONT_SIZES}
	cd ${WRKSRC} && ${SH} fontgen ${font}.ttf ${font}-${size} ${size} \
		2> /dev/null
.endfor
.endfor

do-install:
	@${MKDIR} ${MPLAYER_FONTDIR}
.for font in ${ALL_FONTS}
.for size in ${FONT_SIZES}
	@${TAR} -C ${WRKSRC} -cpf - ${font}-${size} | \
	 ${TAR} -C ${MPLAYER_FONTDIR} -xpf -
.endfor
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
