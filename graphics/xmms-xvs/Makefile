# New ports collection makefile for:	xmms-xvs
# Date created:        			25 June 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-xvs
PORTVERSION=	0.1.0b1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://jgregor.ps.pl/xvs/download/
DISTNAME=	xvs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

XML2_CONFIG?=	${LOCALBASE}/bin/xml2-config
XMMS_CONFIG?=	${X11BASE}/bin/xmms-config

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	XML2_CONFIG="${XML2_CONFIG}" XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibpanel}!=""
USE_GNOME+=	libpanel gnomeprefix
PLIST_SUB+=	DATADIR="share/gnome"
.else
PLIST_SUB+=	DATADIR="share"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<xml|<libxml/xml|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
