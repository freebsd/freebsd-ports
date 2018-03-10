# $FreeBSD$

PORTNAME=	katawa-shoujo
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=-[linux-x86][18161880]
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://dl.katawa-shoujo.com/gold_${PORTVERSION}/:game \
		http://dl.katawa-shoujo.com/patches/:patch \
		GENTOO:icon
DISTFILES=	[4ls]_${DISTNAME:S|-|_|:S|-|_|}${EXTRACT_SUFX}:game \
		${PORTNAME:S|-|_|}_italiano_v1.0.zip:patch \
		${PORTNAME}-48.png:icon \
		${PORTNAME}-256.png:icon
EXTRACT_ONLY=	${DISTFILES:N*\:icon:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bishoujo-style visual novel about disabled adolescents

LICENSE=	CC-BY-NC-ND-3.0

RUN_DEPENDS=	renpy6<6.99.11:devel/renpy6

USES=		tar:bz2
NO_ARCH=	yes
NO_BUILD=	yes
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

post-extract:
	@${MV} ${WRKDIR}/*.rpy* ${WRKSRC}/game/ # :patch

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
