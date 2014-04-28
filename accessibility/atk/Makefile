# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/atk/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	atk
PORTVERSION=	2.12.0
PORTREVISION?=	0
CATEGORIES=	accessibility devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME accessibility toolkit (ATK)

USES=		tar:xz

.if !defined(REFERENCE_PORT)

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build referencehack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	AUTOCONF=${TRUE} AUTOMAKE=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests docs//" \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libatk-1.0.so*

.include <bsd.port.mk>

.endif
