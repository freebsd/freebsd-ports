# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	diffuse
PORTVERSION=	0.4.8
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Graphical n-way diff and merge tool written in Python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CONFLICTS_INSTALL=	tinker-[0-9]*

USES=		desktop-file-utils python:2 tar:bzip2
USE_GNOME=	pygtk2

NO_BUILD=	yes
INSTALLS_ICONS=	yes

PORTDATA=	syntax
PORTDOCS=	AUTHORS ChangeLog ChangeLog_ru README README_ru

OPTIONS_DEFINE=	DATA DOCS NLS
DATA_DESC=	Syntax highlighting support
OPTIONS_DEFAULT=DATA
OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|g; \
		s|../../etc|${PREFIX}/etc|g' ${WRKSRC}/src/usr/bin/${PORTNAME}

post-patch-DATA-on:
	@${REINPLACE_CMD} -e 's|../usr|${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc

post-patch-DATA-off:
	@${REINPLACE_CMD} -e 's|import ../usr|\#(Option disabled!) \
		import ${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc \
		${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src/usr/share/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${STAGEDIR}${DESKTOPDIR}/
	(cd ${WRKSRC}/src/usr/share/icons && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/)
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

do-install-NLS-on:
.for x in cs de es it ja ko pl ru zh_CN zh_TW
	@${MKDIR} ${WRKSRC}/translations/${x}
	${LOCALBASE}/bin/msgfmt -c ${WRKSRC}/translations/${x}.po \
		-o ${WRKSRC}/translations/${x}/${PORTNAME}.mo
	${INSTALL_DATA} ${WRKSRC}/translations/${x}/*.mo \
		${STAGEDIR}${PREFIX}/share/locale/${x}/LC_MESSAGES/
.endfor
.for y in cs it ru
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/${y}/man1
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/${y}/man1/*.1 \
		${STAGEDIR}${MANPREFIX}/man/${y}/man1/
.endfor

.include <bsd.port.mk>
