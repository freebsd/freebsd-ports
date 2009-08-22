# New ports collection makefile for:	osb-jscore
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-jscore
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	lang www java
MASTER_SITES=	SF/gtk-webcore/gtk-webcore/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ WebCore JavaScript interpreter

USE_GNOME=	gnomehack gnometarget gtk20
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-nostdinc++||g' ${WRKSRC}/configure

.include <bsd.port.mk>
