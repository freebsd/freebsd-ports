# New ports collection makefile for:	animenfo-client
# Date created:		3rd August 2001
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	animenfo
PORTVERSION=	20020819
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.animenfo.com/extension/files/
PKGNAMESUFFIX=	-client-gui-gtk${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-client-gui-gtk
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	AnimeNfo client with GTK support

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/animenfo-client-gtk

.include <bsd.port.mk>
