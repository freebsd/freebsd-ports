# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	gnotepad+
PORTVERSION=	1.3.3
PORTREVISION=	10
CATEGORIES=	editors www gnome
MASTER_SITES=	SF/gnotepad/gnotepad-stable/${PORTVERSION} \
		SF/gnotepad/gnotepad%20User_s%20Manual/${DOCVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-based text/HTML editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	xpm
USE_GNOME=	gnomeprefix gtk12
USES=		gettext localbase:ldflags
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-gnome --disable-nls

DOCVERSION=	1.2.0

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

DOCS_DISTFILES=	${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}:doc

post-extract-DOCS-on:
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs

post-patch:
	@${REINPLACE_CMD} -e 's|\(use_gtkhtml=\)yes|\1no|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/destdir/ s|gnulocaledir)|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
