# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mirage
PORTVERSION=	0.9.5.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS/mirageiv

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

USES=		gettext tar:bzip2
USE_GNOME=	gtk20 pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Mirage

PORTDOCS=	CHANGELOG README TODO TRANSLATORS
PORT_VERBS=	${PORTNAME} imgfuncs

OPTIONS_DEFINE=	DOCS GNOME

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	pygnome2
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
