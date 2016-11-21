# Created by: Michael Williams <ports@mgwsoftware.com>
# $FreeBSD$

PORTNAME=	dwarffortress
DISTVERSION=	0.43.05
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.bay12games.com/dwarves/
PKGNAMEPREFIX=	linux-
DISTNAME=	df_${DISTVERSION:S|0.||:S|.|_|}_linux32

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Dwarven fortress building game with ASCII graphics (Linux version)

LICENSE=	BAY12
LICENSE_NAME=	Bay 12 Games Dwarf Fortress Licence
LICENSE_TEXT=	Copyright (c) 2002-2016. All rights are retained by Tarn Adams, \
		save the following: you may redistribute the unmodified binary \
		and accompanying files, provided you do so free of charge. You \
		may distribute modified text files from the data and raw \
		folders (see the readme.txt in those folders for more \
		information). We'd appreciate it if you credit yourself or an \
		alias somewhere for any modifications to prevent confusion \
		with vanilla DF (it helps with bug reports). If you'd like to \
		distribute a modified version of the game or portion of the \
		archive and are worried about copyright infringement, please \
		contact Tarn Adams at toadyone@bay12games.com.
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	linux-${linux_ARGS}-sdl_ttf>0:graphics/linux-${linux_ARGS}-sdl_ttf

USES=		linux tar:bzip2
USE_LINUX=	dri gtk2 libsndfile openal-soft sdlimage xorglibs

SUB_FILES=	dwarffortress
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/df_linux
STRIP=		# breaks execution, changes library ABI to FreeBSD type

ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README.linux readme.txt file\ changes.txt release\ notes.txt \
		command\ line.txt
DESKTOP_ENTRIES="Dwarf Fortress" "" "" "dwarffortress" \
		"Game;Simulation;" false

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dwarffortress ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/dwarffortress
	${BRANDELF} -t Linux ${WRKSRC}/libs/Dwarf_Fortress
	${INSTALL_PROGRAM} ${WRKSRC}/libs/Dwarf_Fortress \
		${STAGEDIR}${PREFIX}/libexec/dwarffortress
	(cd ${WRKSRC}/libs && ${INSTALL_LIB} libgcc_s.so.1 libgraphics.so \
		libstdc++.so.6 ${STAGEDIR}${PREFIX}/libexec/dwarffortress)
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} raw ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "announcement art dipscript \
		help index init initial_movies movies shader.fs shader.vs \
		sound speech" ${STAGEDIR}${DATADIR}/data)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
