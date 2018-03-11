# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	mona
PORTVERSION=	2.90
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
PKGNAMEPREFIX=	ja-font-
DISTNAME=	monafont-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	12,14,16-dot Kanji fonts

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir

USES=		fonts perl5 tar:bzip2
USE_PERL5=	build
NO_ARCH=	yes
MAKE_ENV=	FONTSDIR="${FONTSDIR}"
SUB_FILES=	pkg-message
ALL_TARGET=	bdf

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
