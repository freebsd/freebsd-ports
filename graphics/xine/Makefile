# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xine
#DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	roman@xpert.com

USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
CONFIGURE_ARGS+=	--with-w32-path=${LOCALBASE}/lib/win32

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		xine.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
