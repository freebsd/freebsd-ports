PORTNAME=	gamin
DISTVERSION=	0.1.10
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File and directory monitoring system
WWW=		https://gitlab.gnome.org/Archive/gamin

USES=		gettext gnome libtool localbase pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPPFLAGS+=	-DHAVE_LINUX

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--without-python

OPTIONS_DEFINE=		GAM_POLLER LIBINOTIFY RUN_AS_EUID
OPTIONS_DEFAULT=	RUN_AS_EUID

GAM_POLLER_DESC=	Use gamin's poller instead of kqueue's
LIBINOTIFY_DESC=	Use libinotify as the FAM backend
RUN_AS_EUID_DESC=	Drop privileges to effective user

GAM_POLLER_CPPFLAGS=	-DUSE_GAMIN_POLLER=1
GAM_POLLER_CONFIGURE_ON=	--disable-kqueue

RUN_AS_EUID_CPPFLAGS=	-DRUN_AS_EUID=1

LIBINOTIFY_LDFLAGS=		-linotify
LIBINOTIFY_CONFIGURE_ENABLE=	inotify

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBINOTIFY}
.  if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500050
LIB_DEPENDS+=	libinotify.so:devel/libinotify
.  endif
.endif

post-patch:
	@${REINPLACE_CMD} "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/server/gam_conf.c

do-test:
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} tests)

.include <bsd.port.mk>
