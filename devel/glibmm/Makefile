# New ports collection makefile for:    glibmm
# Date created:         		04 December 2003
# Whom:                 		Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glibmm/Makefile,v 1.90 2010/05/04 12:45:00 kwm Exp $
#

PORTNAME=	glibmm
PORTVERSION=	2.24.2
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

USE_BZIP2=	yes

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/${d}//' ${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.endif
