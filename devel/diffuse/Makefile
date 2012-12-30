# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	diffuse
PORTVERSION=	0.4.6
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	A graphical N-way diff and merge tool written in python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes

USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_GNOME=	pygtk2

CONFLICTS=	tinker-[0-9]*

MAN1=		diffuse.1
PORTDOCS=	AUTHORS ChangeLog ChangeLog_ru README README_ru
PORTDATA=	syntax

OPTIONS_DEFINE=	DATA DOCS MENU NLS
DATA_DESC=	Enable syntax highlighting support
MENU_DESC=	Enable a desktop program menu entry

OPTIONS_DEFAULT=	DATA MENU

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMENU}
USE_GNOME+=	desktopfileutils
PLIST_SUB+=	MENU=""
.else
PLIST_SUB+=	MENU="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
TRANSLATIONS=	de es it ja ko ru zh_CN
MANLANG=	"" it ru
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MDATA}
	${REINPLACE_CMD} -e 's|../usr|${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.else
	${REINPLACE_CMD} -e 's|import ../usr|\#(Option disabled!) \
		import ${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.endif
	${REINPLACE_CMD} -e 's|../../etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/usr/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${MANPREFIX}/man/man1/

post-install:
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${DATADIR}/${PORTDATA}
	(cd ${WRKSRC}/src/usr/share/${PORTNAME} && \
		${COPYTREE_SHARE} \* ${DATADIR})
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MMENU}
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/pixmaps/${PORTNAME}.png \
		${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${DESKTOPDIR}
	${LOCALBASE}/bin/update-desktop-database -q
.endif
.if ${PORT_OPTIONS:MNLS}
.for x in ${TRANSLATIONS}
	${MKDIR} ${WRKSRC}/translations/${x}
	${LOCALBASE}/bin/msgfmt -c ${WRKSRC}/translations/${x}.po \
		-o ${WRKSRC}/translations/${x}/${PORTNAME}.mo
	${INSTALL_DATA} ${WRKSRC}/translations/${x}/*.mo \
		${PREFIX}/share/locale/${x}/LC_MESSAGES/
.endfor
.for y in ${MANLANG}
	${MKDIR} ${MANPREFIX}/man/${y}/man1
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/${y}/man1/*.1 \
		${MANPREFIX}/man/${y}/man1/
.endfor
.endif

.include <bsd.port.mk>
