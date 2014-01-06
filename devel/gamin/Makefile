# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/devel/gamin/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	gamin
PORTVERSION=	0.1.10
PORTREVISION?=	6
CATEGORIES?=	devel
MASTER_SITES=	http://people.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A file and directory monitoring system

USES+=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME?=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-DHAVE_LINUX -I${LOCALBASE}/include

CONFLICTS=	fam-[0-9]*

GNU_CONFIGURE=	yes

.if !defined(GAMIN_SLAVE)
OPTIONS_DEFINE=	GAM_POLLER LIBINOTIFY RUN_AS_EUID
OPTIONS_DEFAULT=RUN_AS_EUID
GAM_POLLER_DESC=Use gamin's poller instead of kqueue's
LIBINOTIFY_DESC=Use libinotify as the FAM backend
RUN_AS_EUID_DESC=Drop privileges to effective user
.endif

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MRUN_AS_EUID}
CPPFLAGS+=	-DRUN_AS_EUID=1
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
