# ports collection makefile for:	gamin
# Date created:				24 March 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gamin
PORTVERSION=	0.0.26
PORTREVISION?=	8
CATEGORIES?=	devel
MASTER_SITES=	http://www.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A file and directory monitoring system

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME?=	gnomehack glib20
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--without-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFLICTS=	fam-[0-9]*

.if !defined(GAMIN_SLAVE)
OPTIONS=	KQUEUE "Enable the KQueue backend (UFS only)" on
.endif

.include <bsd.port.pre.mk>

.if !defined(GAMIN_SLAVE)
.if defined(WITHOUT_KQUEUE)
CONFIGURE_ARGS+=	--disable-kqueue
.else
CONFIGURE_ARGS+=	--enable-kqueue
.endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.post.mk>
