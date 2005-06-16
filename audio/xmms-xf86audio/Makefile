# New ports collection makefile for:   xmms-xf86audio
# Date created:        2005-06-16
# Whom:                Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-xf86audio
PORTVERSION=	0.4.3
CATEGORIES=	audio
MASTER_SITES=	http://www.devin.com/xmms-xf86audio/download/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XF86Audio multimedia-key support for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}" DEBUG=""

do-install:
	${INSTALL_DATA} ${WRKSRC}/libxf86audio.so \
		`xmms-config --general-plugin-dir`
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
