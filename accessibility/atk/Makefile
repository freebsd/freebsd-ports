# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atk
PORTVERSION=	2.24.0
PORTREVISION?=	0
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

LICENSE=	LGPL21

USES=		tar:xz
PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES+=		gettext gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20 introspection:build referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
