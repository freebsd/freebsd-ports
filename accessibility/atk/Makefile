# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/atk/Makefile,v 1.123 2012/10/07 09:00:37 kwm Exp $

PORTNAME=	atk
PORTVERSION=	2.6.0
PORTREVISION?=	0
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehier gnomehack glib20 ltverhack referencehack
USE_PKGCONFIG=	build
CONFIGURE_ARGS=	--enable-static \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	AUTOCONF=${TRUE} AUTOMAKE=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
