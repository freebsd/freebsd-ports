# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unbound
PORTVERSION=	1.4.20
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A validating, recursive, and caching DNS resolver

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE}
USE_LDCONFIG=	yes

USERS=		${PORTNAME}

USE_RC_SUBR=	unbound

MAN1=		unbound-host.1
MAN3=		libunbound.3 ub_cancel.3 ub_ctx.3 ub_ctx_add_ta.3 \
		ub_ctx_add_ta_file.3 ub_ctx_async.3 ub_ctx_config.3 \
		ub_ctx_create.3 ub_ctx_data_add.3 ub_ctx_data_remove.3 \
		ub_ctx_debuglevel.3 ub_ctx_debugout.3 ub_ctx_delete.3 \
		ub_ctx_get_option.3 ub_ctx_hosts.3 ub_ctx_print_local_zones.3 \
		ub_ctx_resolvconf.3 ub_ctx_set_fwd.3 ub_ctx_set_option.3 \
		ub_ctx_trustedkeys.3 ub_ctx_zone_add.3 ub_ctx_zone_remove.3 \
		ub_fd.3 ub_poll.3 ub_process.3 ub_resolve.3 ub_resolve_async.3 \
		ub_resolve_free.3 ub_result.3 ub_strerror.3 ub_wait.3
MAN5=		unbound.conf.5
MAN8=		unbound.8 unbound-anchor.8 unbound-control.8 unbound-checkconf.8

PORTDOCS=	CREDITS Changelog FEATURES LICENSE README README.svn \
		README.tests TODO control_proto_spec.txt ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt
PLIST_SUB+=	PYTHON=${PYTHON} MUNIN=${MUNIN}

OPTIONS_DEFINE=	THREADS PYTHON GOST ECDSA MUNIN
OPTIONS_DEFAULT=THREADS ECDSA

OPTIONS_RADIO=	LIBEVENT
OPTIONS_RADIO_LIBEVENT=	LIBEVENT14 LIBEVENT20

LIBEVENT_DESC=	Enable whenever using many (10000) outgoing ports
LIBEVENT14_DESC=Build against libevent-1.4 (devel/libevent)
LIBEVENT20_DESC=Build against libevent-2.0 (devel/libevent2)
GOST_DESC=	Enable GOST support (requires OpenSSL >= 1.0)
ECDSA_DESC=	Enable ECDSA (elliptic curve) support (OpenSSL >= 1.0)
MUNIN_DESC=	Install Munin plugin

NO_STAGE=	yes
.include <bsd.port.options.mk>

LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2 \
		ldns:${PORTSDIR}/dns/ldns

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-pyunbound=yes --with-pythonmodule=yes
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
PYTHON=
.else
PYTHON=		"@comment "
.endif

.if ${PORT_OPTIONS:MGOST}
. if ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
. endif
DEPENDS_ARGS+=	WITH_GOST=yes
.else
CONFIGURE_ARGS+=--disable-gost
.endif

.if ${PORT_OPTIONS:MECDSA}
DEPENDS_ARGS+=	WITH_ECDSA=yes
.else
CONFIGURE_ARGS+=--disable-ecdsa
.endif

.if ${PORT_OPTIONS:MMUNIN}
SUB_FILES+=	pkg-message
MUNIN_ALL=	hits queue memory by_type by_class by_opcode by_rcode \
		by_flags histogram
MUNIN=
.else
MUNIN=		"@comment "
.endif

.if ${PORT_OPTIONS:MLIBEVENT14}
LIB_DEPENDS+=	event-1:${PORTSDIR}/devel/libevent
CONFIGURE_ARGS+=--with-libevent=${LOCALBASE}
.elif ${PORT_OPTIONS:MLIBEVENT20}
LIB_DEPENDS+=	event-2:${PORTSDIR}/devel/libevent2
USES+=		pkgconfig
CONFIGURE_ARGS+=--with-libevent=${NONEXISTENT}
CONFIGURE_ENV+=	found_libevent=yes
CPPFLAGS+=	$$(pkg-config libevent --cflags-only-I)
LDFLAGS+=	$$(pkg-config libevent --libs-only-L)
.else
CONFIGURE_ARGS+=--with-libevent=no
.endif

.if empty(PORT_OPTIONS:MTHREADS)
CONFIGURE_ARGS+=--without-pthreads
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/balancer
	@${RM} ${WRKSRC}/util/configlexer.c

post-install:
	@${CHOWN} ${USERS} ${ETCDIR}
.if ${PORT_OPTIONS:MMUNIN}
	@${MKDIR} ${PREFIX}/share/munin/plugins
	@${MKDIR} ${PREFIX}/etc/munin/plugins
	@${INSTALL_SCRIPT} ${WRKDIR}/unbound-${PORTVERSION}/contrib/unbound_munin_\
		${PREFIX}/share/munin/plugins/
	@for i in ${MUNIN_ALL}; do\
		${LN} -fs ${PREFIX}/share/munin/plugins/unbound_munin_\
			${PREFIX}/etc/munin/plugins/unbound_munin_$$i ;\
	done
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${CAT} ${WRKDIR}/pkg-message
	@${ECHO_MSG} "============================================================="
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		cd ${WRKSRC}/doc && ${INSTALL_DATA} $${f} ${DOCSDIR}/; \
	done
.endif

.include <bsd.port.mk>
