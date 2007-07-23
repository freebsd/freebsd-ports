# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2.41a
PORTREVISION=	1
CATEGORIES=	lang lisp
MASTER_SITES=	GNU/${PORTNAME}/release/${PORTVERSION:C/[[:alpha:]]+$//} \
		ftp://sunsite.unc.edu/pub/Linux/devel/lang/lisp/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A Common Lisp implementation

BUILD_DEPENDS=	${LOCALBASE}/lib/libsigsegv.a:${PORTSDIR}/devel/libsigsegv \
		dvipdf:${PORTSDIR}/${GHOSTSCRIPT_PORT}
LIB_DEPENDS=	readline.5:${PORTSDIR}/devel/readline

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON=	does not currently support this architecture
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/[[:alpha:]]+$//}
BUILD_WRKSRC=	${WRKSRC}/${CONFIGURE_TARGET}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ENV=	${CONFIGURE_ENV}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEMAKE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man \
		--srcdir=${WRKSRC}/src --with-dynamic-ffi

OPTIONS=	BDB "Build Berkeley Database module" off \
		CLX_MIT "Build X11 module (original MIT version)" off \
		CLX_NEW "Build X11 module (new faster version)" off \
		FASTCGI "Build FastCGI module" off \
		ORACLE "Build Oracle database module" off \
		PARI "Build PARI (math and calculator lib) module" off \
		PCRE "Build PCRE (Perl Compatible Regexp) module" off \
		PGSQL "Build PostgreSQL database module" off \
		RAWSOCK "Build Raw Socket Access module" on \
		WILDCARD "Build wildcard matching module" on \
		ZLIB "Build ZLib interface module " off

MAN1=		clisp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		coredumps when building on FreeBSD 7.x
.endif

MODULES=	BDB CLX_MIT CLX_NEW FASTCGI ORACLE PARI PCRE PGSQL RAWSOCK \
		WILDCARD ZLIB

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--disable-mmap
MAKEMAKE_ARGS+=	--disable-mmap
.endif

.for mod in ${MODULES}
.   if defined(WITH_${mod})
PLIST_SUB+=	${mod}=""
.   else
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if defined(WITH_BDB)
USE_BDB=	42+
MAKEMAKE_ARGS+=	--with-module=berkeley-db
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER}
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER}
.endif

.if defined(WITH_CLX_MIT) && defined(WITH_CLX_NEW)
IGNORE=		selected different implementations of the same X11 module
.endif
.if defined(WITH_CLX_MIT) || defined(WITH_CLX_NEW)
# Avoid USE_XLIB because of the additional CONFIGURE_ARGS.
LIB_DEPENDS+=	X11.6:${X_LIBRARIES_PORT}
.endif
.if defined(WITH_CLX_MIT)
MAKEMAKE_ARGS+=	--with-module=clx/mit-clx
.endif
.if defined(WITH_CLX_NEW)
MAKEMAKE_ARGS+=	--with-module=clx/new-clx
.endif

.if defined(WITH_FASTCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
MAKEMAKE_ARGS+=	--with-module=fastcgi
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS+=	${ORACLE_HOME}:${PORTSDIR}/databases/oracle8-client
MAKEMAKE_ARGS+=	--with-module=oracle
CPPFLAGS+=	-I${ORACLE_HOME}/rdbms/demo -I${ORACLE_HOME}/rdbms/public
LDFLAGS+=	-L${ORACLE_HOME}/lib
ORACLE_HOME=	${LOCALBASE}/oracle8-client
.endif

.if defined(WITH_PARI)
LIB_DEPENDS+=	pari.2:${PORTSDIR}/math/pari
MAKEMAKE_ARGS+=	--with-module=pari
BROKEN=		Lisp stack overflow when building PARI module
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
MAKEMAKE_ARGS+=--with-module=pcre
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MAKEMAKE_ARGS+=	--with-module=postgresql
.endif

.if defined(WITH_RAWSOCK)
MAKEMAKE_ARGS+=	--with-module=rawsock
.endif

.if defined(WITH_WILDCARD)
MAKEMAKE_ARGS+=	--with-module=wildcard
.endif

.if defined(WITH_ZLIB)
MAKEMAKE_ARGS+=	--with-module=zlib
.endif

post-patch:
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -Ee \
		"s|^(subdir_configure_args=')|\1--build=${CONFIGURE_TARGET}|; \
		 s|^(module_configure_flags=')|\1--build=${CONFIGURE_TARGET}|" \
		${WRKSRC}/configure ${WRKSRC}/src/makemake.in
.endif
.if defined(WITH_ORACLE)
	@${REINPLACE_CMD} -e 's|-ldl||; s|-lpthread|-lcompat ${PTHREAD_LIBS}|' \
		${WRKSRC}/modules/oracle/link.sh
.endif

post-configure:
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./makemake ${MAKEMAKE_ARGS} > Makefile && \
		${MAKE} config.lisp
	@${REINPLACE_CMD} -Ee 's|^(CFLAGS =)|\1 ${CPPFLAGS} ${CFLAGS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

.include <bsd.port.post.mk>
