# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unbound
PORTVERSION=	1.5.5
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Validating, recursive, and caching DNS resolver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		autoreconf cpe gmake libtool
CPE_VENDOR=	nlnetlabs
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

OPTIONS_DEFINE=	THREADS PYTHON GOST ECDSA MUNIN DOCS LIBEVENT FILTER_AAAA
OPTIONS_DEFAULT=THREADS ECDSA

LIBEVENT_DESC=	Build against libevent
GOST_DESC=	Enable GOST support (requires OpenSSL >= 1.0)
ECDSA_DESC=	Enable ECDSA (elliptic curve) support (OpenSSL >= 1.0)
MUNIN_DESC=	Install Munin plugin
FILTER_AAAA_DESC=	Build with AAAA filter functionality (contrib)

.include <bsd.port.options.mk>

LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libldns.so:${PORTSDIR}/dns/ldns

STRIP_FILES=	.libs/libunbound.so unbound-checkconf unbound \
		unbound-control .libs/unbound-host .libs/unbound-anchor

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
CONFIGURE_ARGS+=--with-pyunbound=yes --with-pythonmodule=yes LDFLAGS="-L${LOCALBASE}/lib"
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
STRIP_FILES+=	.libs/_unbound.so
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
	@${REINPLACE_CMD} -e 's|if test ! -e $$(DESTDIR)$$(configfile); then || ; \
		s|$$(configfile); fi|$$(configfile).sample|' \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MFILTER_AAAA}
	${CAT} ${WRKSRC}/contrib/aaaa-filter-iterator.patch | ${PATCH} -d ${WRKSRC} -p1 -s
.endif

post-build:
	@for s in ${STRIP_FILES}; do ${STRIP_CMD} ${WRKSRC}/$$s; done

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_unbound.so
.endif
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

regression-test: build
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
