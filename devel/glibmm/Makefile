# New ports collection makefile for:    glibmm
# Date created:         		04 December 2003
# Whom:                 		Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glibmm/Makefile,v 1.31 2006/04/14 21:55:21 mezz Exp $
#

PORTNAME=	glibmm
PORTVERSION=	2.10.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
USE_GNOME=	gnomehack gnometarget glib20
USE_PERL5=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/tests//' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/(docs|examples)//g' ${WRKSRC}/Makefile.in
.endif

.if !defined(NOPORTDOCS)
post-configure:
	@${TOUCH} ${WRKSRC}/docs/reference/html/index.html
.endif

.include <bsd.port.mk>
