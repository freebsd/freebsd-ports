# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	diffuse
PORTVERSION=	0.4.8
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Graphical N-way diff and merge tool written in python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes

USES=		python:2 tar:bzip2
USE_GNOME=	pygtk2

CONFLICTS_INSTALL=	tinker-[0-9]*

PORTDATA=	syntax
PORTDOCS=	AUTHORS ChangeLog ChangeLog_ru README README_ru

OPTIONS_DEFINE=	DATA DOCS MENU NLS
DATA_DESC=	Enable syntax highlighting support
MENU_DESC=	Enable a desktop program menu entry
OPTIONS_DEFAULT=DATA MENU
OPTIONS_SUB=	yes
MENU_USES=	desktop-file-utils
NLS_USES=	gettext

INSTALLS_ICONS=	yes

TRANSLATIONS=	cs de es it ja ko pl ru zh_CN zh_TW
MANUALS=	cs it ru

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|g; \
		s|../../etc|${PREFIX}/etc|g' ${WRKSRC}/src/usr/bin/${PORTNAME}

.if ${PORT_OPTIONS:MDATA}
	${REINPLACE_CMD} -e 's|../usr|${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.else
	${REINPLACE_CMD} -e 's|import ../usr|\#(Option disabled!) \
		import ${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc \
		${STAGEDIR}${PREFIX}/etc/

	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src/usr/share/${PORTNAME} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${STAGEDIR}${DESKTOPDIR}/
	(cd ${WRKSRC}/src/usr/share/icons && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/icons/)

.if ${PORT_OPTIONS:MNLS}
.for x in ${TRANSLATIONS}
	@${MKDIR} ${WRKSRC}/translations/${x}
	${LOCALBASE}/bin/msgfmt -c ${WRKSRC}/translations/${x}.po \
		-o ${WRKSRC}/translations/${x}/${PORTNAME}.mo
	${INSTALL_DATA} ${WRKSRC}/translations/${x}/*.mo \
		${STAGEDIR}${PREFIX}/share/locale/${x}/LC_MESSAGES/
.endfor
.endif

.for y in ${MANUALS}
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/${y}/man1
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/${y}/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/${y}/man1/
.endfor

	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
