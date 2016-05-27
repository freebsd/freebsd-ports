# $FreeBSD$

PORTNAME=	narcissu2
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.neechin.net/file_download/22/:game \
		http://www.neechin.net/file_download/27/:script \
		https://aur.archlinux.org/cgit/aur.git/plain/${PORTNAME}-en.png?h=${PORTNAME}-en\&id=9768eea\&foo=/:icon
DISTFILES=	[Denpa]_Narcissu_2_Eng_[unix].tar.bz2.link:game \
		Narcissu_2_Eng_v${PORTVERSION}_script_[All_platforms].zip:script \
		${PORTNAME}-en.png:icon
EXTRACT_ONLY=	${DISTFILES:N*\:icon:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Visual novel about an encounter of terminally ill

LICENSE=	Freeware
LICENSE_NAME=	Narcissu and Narcissu 2 License (from README)
LICENSE_TEXT=	Permission has been granted to anyone to redistribute \
		these games by means such as the Internet, provided such \
		distribution is free of charge and the contents of the \
		game data are not modified.
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	ponscr:devel/ponscripter-sekai

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-installer
PORTDATA=	*
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png

DESKTOP_ENTRIES="Narcissu & Narcissu: Side 2nd" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;AdventureGame;" \
		""

OPTIONS_DEFINE=	DOCS

pre-install:
	${PRINTF} '#! /bin/sh\nponscr --root ${DATADIR} "$$@"\n' \
		>${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES:M*\:icon:C/:.*//} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} -p ${WRKDIR}/*.utf ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
