# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	jisx0213
PORTVERSION=	20040425
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www12.ocn.ne.jp/~imamura/ \
		LOCAL/hrs:yagi
PKGNAMEPREFIX=	ja-font-
DISTFILES=	jiskan16-2004-1.bdf.gz jiskan16-2000-1.bdf.gz \
		jiskan16-2000-2.bdf.gz K14-2004-1.bdf.gz \
		K14-2000-1.bdf.gz K14-2000-2.bdf.gz \
		K12-1.bdf.gz K12-2.bdf.gz \
		jiskan24-2000-1.bdf.gz:yagi jiskan24-2000-2.bdf.gz:yagi

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese jisx0213 fonts

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USE_XORG=	fontutil
XORG_CAT=	font
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/$${file%.gz}
MAKE_ENV=	STAGEDIR=${STAGEDIR} FONTDIR=${LOCALFONTDIR}
PLIST_SUB=	FONTDIR=${LOCALFONTDIR} XFONTDIR=lib/X11/fonts/${FONTDIR}
SUB_FILES=	Makefile

LOCALFONTDIR=	share/font-${PORTNAME}

pre-build: apply-slist

do-configure:
	@${DO_NADA}

post-install-fontdir:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/X11/fonts/${FONTDIR}
	cd ${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR} && ${LN} -s -f \
	    ${FONTDIR:C,[^/]+,..,g}/../../../${LOCALFONTDIR}/*.pcf.gz .
	${LOCALBASE}/bin/mkfontscale ${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}
	${LOCALBASE}/bin/mkfontdir ${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}

post-install: post-install-fontdir

.include <bsd.port.mk>
