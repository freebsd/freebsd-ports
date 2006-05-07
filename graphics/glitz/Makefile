# New ports collection makefile for:	glitz
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#   $MCom: ports/graphics/glitz/Makefile,v 1.4 2005/08/09 22:54:54 ahze Exp $
#

PORTNAME=	glitz
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL image compositing library

USE_GL=		yes
USE_GNOME=	pkgconfig gnometarget gnomehack
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/src/glitz.h
.endif

.include <bsd.port.post.mk>
