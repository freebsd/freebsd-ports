# ports collection makefile for:	gamin
# Date created:				24 March 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gamin
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES?=	devel
MASTER_SITES=	http://www.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A file and directory monitoring system

USE_GMAKE=	yes
USE_GNOME?=	gnomehack glib20
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--without-python --disable-debug
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFLICTS=	fam-[0-9]*

.if defined(GAMIN_SLAVE)
USE_LIBTOOL_VER=15
.else
USE_INC_LIBTOOL_VER=15
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.if !defined(GAMIN_SLAVE)
tests: build
	@${ECHO_MSG} "===> Running gamin regression tests"
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} tests)

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
