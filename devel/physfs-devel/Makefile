# New ports collection makefile for:	physfs
# Date Created:		26 July 2003
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	physfs
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://offload1.icculus.org/${PORTNAME}/downloads/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library to provide abstract access to various archives

USE_GNOME=	gnometarget
#GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
NO_LATEST_LINK=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|-D_REENTRANT -D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' \
		${WRKSRC}/configure
.include <bsd.port.mk>
