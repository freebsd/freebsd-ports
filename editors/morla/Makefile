# New ports collection makefile for:	morla
# Date created:		2006-04-09
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	morla
PORTVERSION=	0.6
CATEGORIES=	editors textproc
MASTER_SITES=	http://www2.autistici.org/bakunin/morla/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@email.it
COMMENT=	A RDF editor

LIB_DEPENDS=	nxml.0:${PORTSDIR}/textproc/libnxml \
		rdf.0:${PORTSDIR}/textproc/redland
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I/${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	libgtkhtml libxslt

DESKTOP_ENTRIES="morla" \
		"Edit RDF documents" \
		"${DATADIR}/icons/128_color.png" \
		"morla" \
		"Application;WebDevelopment;" \
		true

.include <bsd.port.mk>
