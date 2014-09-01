# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/atk/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	atk
PORTVERSION=	2.8.0
PORTREVISION?=	1
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	AUTOCONF=${TRUE} AUTOMAKE=${TRUE}
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
