# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mona
PORTVERSION=	2.90
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-ttf
DISTNAME=	monafont-ttf-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	TrueType Kanji fonts

LICENSE=	PD

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60
FONTNAME=	${PORTNAME}${PKGNAMESUFFIX}
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${FONTSDIR:S,${PREFIX}/,,}/fonts.dir \
		${FONTSDIR:S,${PREFIX}/,,}/mona.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/mona.ttf ${FILESDIR}/fonts.dir \
	    ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
