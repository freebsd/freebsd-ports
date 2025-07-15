PORTNAME=	narcissu2
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.neechin.net/file_download/22/:game \
		http://www.neechin.net/file_download/27/:script \
		https://github.com/07th-mod/ponscripter-fork/raw/v3.0.2/src/resources/:icon
DISTFILES=	[Denpa]_Narcissu_2_Eng_[unix].tar.bz2:game \
		Narcissu_2_Eng_v${PORTVERSION}_script_[All_platforms].zip:script \
		narci2.ico:icon narci2.png:icon
EXTRACT_ONLY=	${DISTFILES:N*\:icon:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Visual novel about an encounter of terminally ill
WWW=		https://www.neechin.net/narcissu/

LICENSE=	Freeware
LICENSE_NAME=	Narcissu and Narcissu 2 License (from README)
LICENSE_TEXT=	Permission has been granted to anyone to redistribute \
		these games by means such as the Internet, provided such \
		distribution is free of charge and the contents of the \
		game data are not modified.
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	ponscr:games/ponscripter-07th-mod

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-installer
PORTDATA=	*
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man6/${PORTNAME}.6.gz \
		share/pixmaps/narci2.ico \
		share/pixmaps/narci2.png

DESKTOP_ENTRIES="Narcissu & Narcissu: Side 2nd" \
		"" \
		"narci2" \
		"${PORTNAME}" \
		"Game;AdventureGame;" \
		""

OPTIONS_DEFINE=	DOCS

pre-install:
	${PRINTF} '#! /bin/sh\nponscr --root ${DATADIR} "$$@"\n' \
		>${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTFILES:M*\:icon:C/:.*//:S,^,${DISTDIR}/,} \
		${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} -p ${WRKDIR}/*.utf ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 \
		${STAGEDIR}${PREFIX}/share/man/man6/${PORTNAME}.6
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
