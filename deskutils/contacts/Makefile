# Created by: Piotr SMyrak, smyru@heron.pl
# $FreeBSD$

PORTNAME=	contacts
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://pimlico-project.org/sources/${PORTNAME}/
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@freebsd.org
COMMENT=	Simple yet powerful address book based on Evolution data server

DEPRECATED=		upstream project discontinued for years, upstream sources are gone
EXPIRATION_DATE=	2013-06-13

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehier evolutiondataserver gnomevfs2
USE_AUTOTOOLS=	libtool
GCONF_SCHEMAS=	contacts.schemas
MAN1=		${PORTNAME}.1
# CFLAGS+=	-g

.include <bsd.port.mk>
