# $FreeBSD$

PORTNAME=	katawa-shoujo
PORTVERSION=	1.3
DISTVERSIONSUFFIX=-[linux-x86][FCF758CC]
CATEGORIES=	games
MASTER_SITES=	http://dl.katawa-shoujo.com/gold_${PORTVERSION}/:game \
		GENTOO:icon
DISTFILES=	[4ls]_${DISTNAME:S|-|_|:S|-|_|}${EXTRACT_SUFX}:game \
		${PORTNAME}-48.png:icon \
		${PORTNAME}-256.png:icon
EXTRACT_ONLY=	[4ls]_${DISTNAME:S|-|_|:S|-|_|}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bishoujo-style visual novel about disabled adolescents

LICENSE=	CCbyNCND3
LICENSE_NAME=	Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported
LICENSE_TEXT=	See https://creativecommons.org/licenses/by-nc-nd/3.0/
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	renpy:${PORTSDIR}/devel/renpy

USES=		tar:bz2
NO_ARCH=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/Katawa\ Shoujo-${PORTVERSION}-linux
PORTDATA=	*
PORTDOCS=	*.pdf
PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/icons/hicolor/256x256/apps/${PORTNAME}.png

DESKTOP_ENTRIES="Katawa Shoujo" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;AdventureGame;" \
		""

OPTIONS_DEFINE=	DOCS

pre-install:
	${PRINTF} '#! /bin/sh\nrenpy ${DATADIR} "$$@"\n' \
		>${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for i in 48 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PORTNAME}.png
.endfor
	(cd ${WRKSRC}/game && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
