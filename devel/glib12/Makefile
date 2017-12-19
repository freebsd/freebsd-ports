# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib
PORTVERSION=	1.2.10
PORTREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	12

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (previous stable version)

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

INFO=		glib

post-install:
	${LN} -sf glib-config ${STAGEDIR}${PREFIX}/bin/glib12-config

.include <bsd.port.mk>
