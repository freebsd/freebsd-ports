# New ports collection makefile for:	gobject-introspection
# Date created:				19 July 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gobject-introspection/Makefile,v 1.39 2011/06/11 19:51:15 mezz Exp $
#

PORTNAME=	gobject-introspection
PORTVERSION=	0.10.8
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_PYTHON=	-2.7
USE_BISON=	build
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-tests

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

MAN1=		g-ir-compiler.1 g-ir-generate.1 g-ir-scanner.1


post-patch:
	@${REINPLACE_CMD} -e "s|'cc'|'${CC:Q:C/[[:space:]]+/', '/g}'|g" \
		${WRKSRC}/giscanner/sourcescanner.py

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.include <bsd.port.post.mk>
