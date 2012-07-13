# New ports collection Makefile for:	fxite
# Date created:				23 August 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	fxite
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An advanced cross-platform text editor

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_GETTEXT=	yes
USE_LUA=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CXXFLAGS+=	-g -O0 -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=--with-system-lua \
		--with-lua-pkg=lua-${LUA_VER}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800067
LIB_DEPENDS+=	getline.1:${PORTSDIR}/devel/libgetline
LDFLAGS+=	-lgetline
.endif

PLIST_FILES=	bin/fxite

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	   ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
