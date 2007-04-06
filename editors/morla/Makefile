# New ports collection makefile for:	morla
# Date created:		2006-04-09
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	morla
PORTVERSION=	0.11
CATEGORIES=	editors textproc
MASTER_SITES=	http://www2.autistici.org/bakunin/morla/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A RDF editor

LIB_DEPENDS=	nxml.0:${PORTSDIR}/textproc/libnxml \
		rdf.0:${PORTSDIR}/textproc/redland
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I/${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
USE_GETTEXT=	yes
USE_GNOME=	libgtkhtml libxslt

MAN1=	morla.1

DESKTOP_ENTRIES="morla" \
		"Edit RDF documents" \
		"${DATADIR}/icons/128_color.png" \
		"morla" \
		"Application;WebDevelopment;" \
		true

.include <bsd.port.mk>
