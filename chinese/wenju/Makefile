# New ports collection makefile for:   wenju
# Date created:                18 Oct 2003
# Whom:                        Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wenju
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wenju

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of writing tools in Chinese

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
USE_LIBTOOL_VER=	13

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
		gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
EXTRA_PATCHES+=	${FILESDIR}/configure-getopt.patch
.endif

.include <bsd.port.post.mk>
