# New ports collection makefile for:	ruby_static
# Date created:			19 February 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby_static
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../../${RUBY_PORT}:patch

USE_RUBY=	yes

USE_AUTOCONF=	yes

# Beware, because gdbm is under GPL, you must treat the whole binary
# as GPL says.
EXT_PORTS=	archivers/ruby-zlib \
		devel/ruby-strscan
_PORTSDIR=	${.CURDIR}/../..
_RUBY_PORTDIR=	${_PORTSDIR}/${RUBY_PORT}

.if !defined(HAVE_FNMATCH)
EXT_PORTS+=	devel/ruby-fnmatch
.endif

.for p in ${EXT_PORTS}
BUILD_DEPENDS+=	${NONEXISTENT}:${_PORTSDIR}/${p}:patch
.endfor

WRKSRC=		${RUBY_WRKSRC}

DESCR=		${_RUBY_PORTDIR}/pkg-descr

.include <bsd.port.pre.mk>

# You can build a totally statically linked binary by defining STATIC,
# although it is not capable of loading dynamic modules.

CONFIGURE_ENV=	XLDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS!=	cd ${_RUBY_PORTDIR} && ${MAKE} -V CONFIGURE_ARGS
.if defined(STATIC)
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N--enable-shared:M-*} \
			--with-static-linked-ext=yes \
			--with-opt-dir="${LOCALBASE}"
.else
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:M-*} \
			--with-opt-dir="${LOCALBASE}"
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT}

do-fetch:
	@${DO_NADA}

.if defined(STATIC)
post-patch:
	${RUBY} -i -pe 'gsub /-rdynamic/, "-static"' ${WRKSRC}/configure.in
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${_RUBY_PORTDIR} && ${MAKE} -V WRKSRC` ${WRKSRC}
.for p in ${EXT_PORTS}
	wrksrc=$$(cd ${_PORTSDIR}/${p} && ${MAKE} -V WRKSRC) ; \
	extdir=$$(find -L $$wrksrc -name extconf.rb); \
	extdir=$${extdir%/extconf.rb}; \
	${CP} -RPp $$extdir ${WRKSRC}/ext/
.endfor
.if defined(STATIC)
	${ECHO} "option nodynamic" > ${WRKSRC}/ext/Setup
.else
	${ECHO} "#option nodynamic" > ${WRKSRC}/ext/Setup
.endif
	(cd ${WRKSRC}/ext && \
	for x in *; do [ -d $$x ] && echo $$x >> Setup; done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${RUBY_NAME} ${RUBY_WITH_SUFFIX}_s
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	${LN} -fs ruby${_RUBY_SUFFIX}_s ${RUBY_WITHOUT_SUFFIX}_s
.endif

.include <bsd.port.post.mk>
