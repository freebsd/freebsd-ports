# New ports collection makefile for:	Gnocky
# Date created:				16 Jul 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocky
PORTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnocky/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A graphical (GTK+2) frontend for gnokii

LIB_DEPENDS=	gnokii.4:${PORTSDIR}/comms/gnokii

USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NLS	"Build with Native Language Support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
