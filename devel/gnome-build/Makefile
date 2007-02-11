# New ports collection makefile for:	gnomebuild
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-build
PORTVERSION=	0.1.3
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Build Framework (GBF)

LIB_DEPENDS=	gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui gnomevfs2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES+=	${FILESDIR}/current-src_backends_libgbf_am_gbf-am-project.c
.elif ${ARCH} != "i386"
EXTRA_PATCHES+=	${FILESDIR}/stable-src_backends_libgbf_am_gbf-am-project.c
.endif

.include <bsd.port.post.mk>
