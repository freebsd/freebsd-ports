# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	mona
PORTVERSION=	2.90
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
PKGNAMEPREFIX=	ja-font-
DISTNAME=	monafont-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	12,14,16-dot Kanji fonts

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir

USES=		fonts perl5 tar:bzip2
FONTNAME=	misc
USE_PERL5=	build
NO_ARCH=	yes
MAKE_ENV=	DATADIR="${DATADIR}"
SUB_FILES=	pkg-install
SUB_LIST=	FONTSALIAS="${DATADIR}/fonts.alias"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
ALL_TARGET=	bdf

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.pcf.gz .
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
