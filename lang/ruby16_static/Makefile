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

# Beware, you can't statically link Ruby with GPL'ed libraries,
# which means you can't link such modules as ruby-gdbm within.
EXT_PORTS=	archivers/ruby-zlib \
		devel/ruby-strscan \
		sysutils/ruby-syslog
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

CONFIGURE_ENV=	XLDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS!=	cd ${_RUBY_PORTDIR} && ${MAKE} -V CONFIGURE_ARGS
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N--enable-shared:M-*} \
			--with-static-linked-ext=yes \
			--with-opt-dir="${LOCALBASE}"

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT}

do-fetch:
	@${DO_NADA}

post-patch:
	${RUBY} -i -pe 'gsub /-rdynamic/, "-static"' ${WRKSRC}/configure.in

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${_RUBY_PORTDIR} && ${MAKE} -V WRKSRC` ${WRKSRC}
.for p in ${EXT_PORTS}
	wrksrc=$$(cd ${_PORTSDIR}/${p} && ${MAKE} -V WRKSRC) ; \
	extdir=$$(find $$wrksrc -name extconf.rb); \
	extdir=$${extdir%/extconf.rb}; \
	${CP} -RPp $$extdir ${WRKSRC}/ext/
.endfor
	(cd ${WRKSRC}/ext && \
	${ECHO} "option nodynamic" > Setup; \
	for x in *; do [ -d $$x ] && echo $$x >> Setup; done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${RUBY_NAME} ${RUBY_WITH_SUFFIX}_s
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	${LN} -fs ruby${_RUBY_SUFFIX}_s ${RUBY_WITHOUT_SUFFIX}_s
.endif

.include <bsd.port.post.mk>
