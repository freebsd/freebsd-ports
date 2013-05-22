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

USE_BZIP2=	yes
USE_GNOME=	gtk20 pygtk2
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Mirage

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README TODO TRANSLATORS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
