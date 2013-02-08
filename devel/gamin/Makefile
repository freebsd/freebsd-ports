# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/devel/gamin/Makefile,v 1.11 2012/08/04 16:55:24 kwm Exp $

PORTNAME=	gamin
PORTVERSION=	0.1.10
PORTREVISION?=	4
CATEGORIES?=	devel
MASTER_SITES=	http://people.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A file and directory monitoring system

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME?=	gnomehack _glib20
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-DHAVE_LINUX -I${LOCALBASE}/include ${PTHREAD_CFLAGS}

CONFLICTS=	fam-[0-9]*

GNU_CONFIGURE=	yes

.if !defined(GAMIN_SLAVE)
OPTIONS_DEFINE=	GAM_POLLER LIBINOTIFY
GAM_POLLER_DESC=Use gamin's poller instead of kqueue's
LIBINOTIFY_DESC=Use libinotify as the FAM backend
.endif

.include <bsd.port.options.mk>

.if !defined(GAMIN_SLAVE)
.if ${PORT_OPTIONS:MGAM_POLLER}
CPPFLAGS+=	-DUSE_GAMIN_POLLER=1
.endif

.if ${PORT_OPTIONS:MLIBINOTIFY}
CONFIGURE_ARGS+=--enable-inotify
LDFLAGS+=	-L${LOCALBASE}/lib -linotify
LIB_DEPENDS+=	inotify:${PORTSDIR}/devel/libinotify
.else
CONFIGURE_ARGS+=--disable-inotify
.endif
.endif

post-patch:
	@${REINPLACE_CMD} "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/server/gam_conf.c

.if !defined(GAMIN_SLAVE)
regression-test: build
	@${ECHO_MSG} "===> Running gamin regression tests"
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} tests)

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
