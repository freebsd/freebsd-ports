# New ports collection makefile for:	morla
# Date created:		2006-04-09
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	morla
PORTVERSION=	0.15
#PORTREVISION=	0
CATEGORIES=	editors textproc
MASTER_SITES=	http://www.morlardf.net/src/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A RDF editor

LIB_DEPENDS=	nxml.18:${PORTSDIR}/textproc/libnxml \
		rdf.0:${PORTSDIR}/textproc/redland \
		curl.4:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I/${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes
USE_GNOME=	libgtkhtml libxslt
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

MAN1=	morla.1

DESKTOP_ENTRIES="morla" \
		"Edit RDF documents" \
		"${DATADIR}/icons/128_color.png" \
		"morla" \
		"Application;WebDevelopment;" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
