# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/ghex/Makefile,v 1.13 2008/08/23 18:22:59 mezz Exp $

PORTNAME=	ghex
PORTVERSION=	2.24.0
PORTREVISION=	6
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 hex editor

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnomeprintui libgnomeui gnomedocutils
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	ghex2.schemas

post-patch:
	@${REINPLACE_CMD} '/^ghex2_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
