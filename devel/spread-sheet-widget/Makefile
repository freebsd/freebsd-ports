# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spread-sheet-widget
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	GNU_ALPHA
MASTER_SITE_SUBDIR=	ssw

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Library for Gtk+ which provides a widget for tabular data

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome libtool makeinfo pkgconfig
USE_GNOME=	atk glib20 gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
INFO=		spread-sheet-widget

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
