# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	myBudget
PORTVERSION=	0.60
PORTREVISION=	9
CATEGORIES=	finance gnome
MASTER_SITES=	http://www.abisource.com/~msevior/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+-2 finance manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes
USE_GNOME=	pygnome2
INSTALL_ICONS=	yes

USES=		python:2.7 shebangfix
SHEBANG_FILES=	myBudget.py

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		"/^sPREFIX/s|=.*| = '${PREFIX}/share'|" ${WRKSRC}/myBudget.py

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} myBudget.py \
		${STAGEDIR}${PREFIX}/bin/myBudget)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.myb *.png *.txt \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/glade
	(cd ${WRKSRC}/glade && ${INSTALL_DATA} *.* \
		${STAGEDIR}${DATADIR}/glade)
	@${MKDIR} ${STAGEDIR}${DATADIR}/po
	(cd ${WRKSRC}/po && ${INSTALL_DATA} *.po \
		${STAGEDIR}${DATADIR}/po)
	(cd ${WRKSRC} && ${INSTALL_DATA} *.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC} && ${INSTALL_DATA} *.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
