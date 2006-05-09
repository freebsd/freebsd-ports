# New ports collection makefile for:	osb-jscore
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-jscore
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	lang www java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Javascript interpreter port from Apple's KHTML and part of Gtk-Webcore

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-pic

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/kjs/ustring.h
.endif
	@${REINPLACE_CMD} -e 's|-lpthread||; s|-nostdinc++||; \
		s|-nodefaultlibs||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
