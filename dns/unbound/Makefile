# New ports collection makefile for:	unbound
# Date created:				25 Apr 2008
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unbound
PORTVERSION=	1.3.3
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A validating, recursive, and caching DNS resolver

USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
USE_LDCONFIG=	yes

USE_RC_SUBR=	unbound

MAN1=		unbound-host.1
MAN3=		libunbound.3
MAN5=		unbound.conf.5
MAN8=		unbound.8 unbound-control.8 unbound-checkconf.8

PORTDOCS=	CREDITS Changelog FEATURES LICENSE README README.svn \
		README.tests TODO control_proto_spec.txt ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall
PLIST_SUB+=	PYTHON=${PYTHON}

OPTIONS=	LIBEVENT "is useful when using many (10000) outgoing ports" off \
		THREADS "build with threads support" on \
		PYTHON "build python bindings" off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-pyunbound=yes --with-pythonmodule=yes
BUILD_DEPENDS+=		swig:${PORTSDIR}/devel/swig13
PYTHON=
.else
PYTHON=		"@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} < 700000
BROKEN=		Does not build on sparc64-6
.endif

.if defined(WITH_LIBEVENT)
LIB_DEPENDS+=		event-1.4:${PORTSDIR}/devel/libevent
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-libevent=no
.endif

.if !defined(WITH_THREADS)
CONFIGURE_ARGS+=	--without-pthreads
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/balancer
	@${RM} ${WRKSRC}/util/configlexer.c

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		cd ${WRKSRC}/doc && ${INSTALL_DATA} $${f} ${DOCSDIR}/; \
	done
.endif

.include <bsd.port.post.mk>
