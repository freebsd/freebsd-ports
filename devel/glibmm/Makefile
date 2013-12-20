# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/glibmm/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	glibmm
PORTVERSION=	2.38.1
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

USE_XZ=		yes

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		gettext gmake pathfix perl5 pkgconfig
USE_GNOME=	glib20 ltverhack libsigc++20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
ltverhack_PATCH_FILES=build/ltmain.sh

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/${d}//' ${WRKSRC}/Makefile.in
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*-2.4.so.1

.include <bsd.port.mk>

.endif
