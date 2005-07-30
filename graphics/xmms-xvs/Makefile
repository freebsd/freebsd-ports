# New ports collection makefile for:	xmms-xvs
# Date created:        			25 June 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-xvs
PORTVERSION=	0.1.0b1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://jgregor.ps.pl/software/xvs/download/
DISTNAME=	xvs-${PORTVERSION}

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Visualization System, a plugin for XMMS

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

XMMS_CONFIG?=	${X11BASE}/bin/xmms-config

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GNOME=	gtk12 libxml2
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|<xml|<libxml/xml|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
