# New ports collection makefile for:	xmms-xvs
# Date created:        			25 June 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-xvs
PORTVERSION=	0.1.0b1
CATEGORIES=	graphics
MASTER_SITES=	http://godot.tuniv.szczecin.pl/~jgregor/xvs/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	xvs-${PORTVERSION}

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XML2_CONFIG="${LOCALBASE}/bin/xml2-config" \
		XMMS_CONFIG="${X11BASE}/bin/xmms-config"
USE_GMAKE=	yes
USE_X_PREFIX=	yes

DOCS=	AUTHORS ChangeLog NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
