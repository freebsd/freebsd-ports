# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	diffuse
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Graphical N-way diff and merge tool written in python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes

USE_BZIP2=	yes
USE_PYTHON=	2
USE_GNOME=	pygtk2

CONFLICTS=	tinker-[0-9]*

PORTDOCS=	AUTHORS ChangeLog ChangeLog_ru README README_ru

OPTIONS_DEFINE=	DATA DOCS MENU NLS
DATA_DESC=	Enable syntax highlighting support
MENU_DESC=	Enable a desktop program menu entry
OPTIONS_DEFAULT=DATA DOCS MENU NLS
OPTIONS_SUB=	yes
MENU_USES=	desktop-file-utils
NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATA}
PORTDATA=	syntax
.endif

.if ${PORT_OPTIONS:MNLS}
TRANSLATIONS=	cs de es it ja ko pl ru zh_CN
MANUALS=	cs it ru
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
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|g; \
		s|../../etc|${PREFIX}/etc|g' ${WRKSRC}/src/usr/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc \
		${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

.if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTDATA}
	(cd ${WRKSRC}/src/usr/share/${PORTNAME} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/)
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)
.endif

.if ${PORT_OPTIONS:MMENU}
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/pixmaps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${STAGEDIR}${DESKTOPDIR}/
.endif

.if ${PORT_OPTIONS:MNLS}
.for x in ${TRANSLATIONS}
	@${MKDIR} ${WRKSRC}/translations/${x}
	${LOCALBASE}/bin/msgfmt -c ${WRKSRC}/translations/${x}.po \
		-o ${WRKSRC}/translations/${x}/${PORTNAME}.mo
	${INSTALL_DATA} ${WRKSRC}/translations/${x}/*.mo \
		${STAGEDIR}${PREFIX}/share/locale/${x}/LC_MESSAGES/
.endfor
.for y in ${MANUALS}
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/${y}/man1
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/${y}/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/${y}/man1/
.endfor
.endif

.include <bsd.port.mk>
