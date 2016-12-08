# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/devel/gamin/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	gamin
PORTVERSION=	0.1.10
PORTREVISION?=	9
CATEGORIES?=	devel
MASTER_SITES=	http://people.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	File and directory monitoring system

USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME?=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
CPPFLAGS+=	-DHAVE_LINUX -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CONFLICTS=	fam-[0-9]*

.if !defined(GAMIN_SLAVE)
OPTIONS_DEFINE=	GAM_POLLER LIBINOTIFY RUN_AS_EUID
OPTIONS_DEFAULT=RUN_AS_EUID
GAM_POLLER_DESC=Use gamin's poller instead of kqueue's
LIBINOTIFY_DESC=Use libinotify as the FAM backend
RUN_AS_EUID_DESC=Drop privileges to effective user
.endif

.include <bsd.port.options.mk>

.if !defined(GAMIN_SLAVE)
.if ${PORT_OPTIONS:MGAM_POLLER}
CPPFLAGS+=	-DUSE_GAMIN_POLLER=1
.endif

.if ${PORT_OPTIONS:MLIBINOTIFY}
CONFIGURE_ARGS+=--enable-inotify
LIBS+=		-linotify
LIB_DEPENDS+=	libinotify.so:devel/libinotify
.else
CONFIGURE_ARGS+=--disable-inotify
.endif
.endif

.if ${PORT_OPTIONS:MRUN_AS_EUID}
CPPFLAGS+=	-DRUN_AS_EUID=1
.endif

post-patch:
	@${REINPLACE_CMD} "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/server/gam_conf.c

.if !defined(GAMIN_SLAVE)
regression-test: build
	@${ECHO_MSG} "===> Running gamin regression tests"
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} tests)
.endif

.include <bsd.port.mk>
