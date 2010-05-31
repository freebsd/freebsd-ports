# New ports collection makefile for:	atk
# Date Created:				14 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/atk/Makefile,v 1.104 2010/04/02 16:56:50 kwm Exp $
#

PORTNAME=	atk
PORTVERSION=	1.30.0
PORTREVISION?=	1
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME accessibility toolkit (ATK)

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack glib20 ltverhack referencehack
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		AUTOCONF=${TRUE} AUTOMAKE=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
