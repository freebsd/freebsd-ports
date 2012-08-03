# New ports collection makefile for:	unbound
# Date created:				25 Apr 2008
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unbound
PORTVERSION=	1.4.18
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
MAN3=		libunbound.3
MAN5=		unbound.conf.5
MAN8=		unbound.8 unbound-anchor.8 unbound-control.8 unbound-checkconf.8

PORTDOCS=	CREDITS Changelog FEATURES LICENSE README README.svn \
		README.tests TODO control_proto_spec.txt ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt
PLIST_SUB+=	PYTHON=${PYTHON} MUNIN=${MUNIN}

OPTIONS_DEFINE=	LIBEVENT THREADS PYTHON GOST ECDSA MUNIN
OPTIONS_DEFAULT=THREADS ECDSA

LIBEVENT_DESC=	Enable whenever using many (10000) outgoing ports
GOST_DESC=	Enable GOST support (requires OpenSSL from ports)
ECDSA_DESC=	Enable ECDSA (elliptic curve) support
MUNIN_DESC=	Install Munin plugin

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
WITH_OPENSSL_PORT=	yes
DEPENDS_ARGS+=	WITH_GOST=yes
.else
CONFIGURE_ARGS+=--disable-gost
.endif

.if ${PORT_OPTIONS:MECDSA}
WITH_OPENSSL_PORT=yes
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
LIB_DEPENDS+=	event-1:${PORTSDIR}/devel/libevent
CONFIGURE_ARGS+=--with-libevent=${LOCALBASE}
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
	@${INSTALL_DATA} ${WRKDIR}/unbound-${PORTVERSION}/contrib/unbound_munin_\
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		cd ${WRKSRC}/doc && ${INSTALL_DATA} $${f} ${DOCSDIR}/; \
	done
.endif

.include <bsd.port.mk>
