# New ports collection makefile for:	gnomebuild
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebuild
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/gnome/gnome-/}/0.1
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	A GNOME Build Framework (GBF)

LIB_DEPENDS=	gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack lthack gnometarget libgnomeui gnomevfs2
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES+=	${FILESDIR}/current-src_backends_libgbf_am_gbf-am-project.c
.elif ${ARCH} != "i386"
EXTRA_PATCHES+=	${FILESDIR}/stable-src_backends_libgbf_am_gbf-am-project.c
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -Ee \
		's|-D[^[:space:]_]+_DISABLE_DEPRECATED||g'

.include <bsd.port.post.mk>
