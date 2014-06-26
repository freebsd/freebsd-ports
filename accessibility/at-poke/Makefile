# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD$

PORTNAME=	at-poke
PORTVERSION=	0.2.3
PORTREVISION=	7
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

DEPRECATED=	Depends on expired libgailgnome
EXPIRATION_DATE=2014-07-21

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Accessibility testing and poking tool

LICENSE=	GPLv2

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix libglade2 libgailgnome
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/eventlog.h

.include <bsd.port.mk>
