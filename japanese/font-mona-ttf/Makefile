# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mona
PORTVERSION=	2.90
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-ttf
DISTNAME=	monafont-ttf-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	TrueType Kanji fonts

USES=		fonts:fc zip
FONTNAME=	TTF
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-install
SUB_LIST=	DIRFILE="${DATADIR}/fonts.dir"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
MAKE_ENV=	FONTSDIR=${FONTSDIR:S,${PREFIX},,}
PLIST_FILES=	%%DATADIR%%/fonts.dir \
		%%DATADIR%%/mona.ttf \
		%%FONTSDIR%%/mona.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mona.ttf ${FILESDIR}/fonts.dir \
	    ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.ttf .

.include <bsd.port.mk>
