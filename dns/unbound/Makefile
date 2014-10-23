# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unbound
PORTVERSION=	1.4.22
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Validating, recursive, and caching DNS resolver

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		gmake libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE} --with-libexpat=${LOCALBASE}
USE_LDCONFIG=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

USE_RC_SUBR=	unbound

PORTDOCS=	CREDITS Changelog FEATURES LICENSE README README.svn \
		README.tests TODO control_proto_spec.txt ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt
PLIST_SUB+=	PYTHON=${PYTHON} MUNIN=${MUNIN}

OPTIONS_DEFINE=	THREADS PYTHON GOST ECDSA MUNIN DOCS LIBEVENT
OPTIONS_DEFAULT=THREADS ECDSA

LIBEVENT_DESC=	Build against libevent (devel/libevent2) (BROKEN on >=10)
GOST_DESC=	Enable GOST support (requires OpenSSL >= 1.0)
ECDSA_DESC=	Enable ECDSA (elliptic curve) support (OpenSSL >= 1.0)
MUNIN_DESC=	Install Munin plugin

.include <bsd.port.options.mk>

LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libldns.so:${PORTSDIR}/dns/ldns

STRIP_FILES=	.libs/libunbound.so unbound-checkconf unbound \
		unbound-control .libs/unbound-host .libs/unbound-anchor

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=--with-pyunbound=yes --with-pythonmodule=yes
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
PYTHON=
.else
PYTHON=		"@comment "
.endif

.if ${PORT_OPTIONS:MGOST}
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000015
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

.if ${PORT_OPTIONS:MLIBEVENT}
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000015
BROKEN=	Unbound with libevent crashes on FreeBSD 10+ due to Capsicum
.endif
LIB_DEPENDS+=	libevent.so:${PORTSDIR}/devel/libevent2
USES+=		pkgconfig
CONFIGURE_ARGS+=--with-libevent
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

post-build:
	@for s in ${STRIP_FILES}; do ${STRIP_CMD} ${WRKSRC}/$$s; done

post-install:
.if ${PORT_OPTIONS:MMUNIN}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/munin/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/munin/plugins
	@${INSTALL_SCRIPT} ${WRKDIR}/unbound-${PORTVERSION}/contrib/unbound_munin_\
		${STAGEDIR}${PREFIX}/share/munin/plugins/
	@for i in ${MUNIN_ALL}; do\
		${LN} -fs ${PREFIX}/share/munin/plugins/unbound_munin_\
			${STAGEDIR}${PREFIX}/etc/munin/plugins/unbound_munin_$$i ;\
	done
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${CAT} ${WRKDIR}/pkg-message
	@${ECHO_MSG} "============================================================="
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		cd ${WRKSRC}/doc && ${INSTALL_DATA} $${f} ${STAGEDIR}${DOCSDIR}/; \
	done
.endif

.include <bsd.port.mk>
