# New ports collection makefile for:	ruby_static
# Date created:			19 February 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby_static
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION?=	1
CATEGORIES=	lang ruby ipv6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binary with some modules compiled in (in case of emergency)

EXTRACT_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../../${RUBY_PORT}:patch

USE_RUBY=	yes

RUBY_VER?=	1.6

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${RUBY_VER} == 1.6
BROKEN=		"Configure fails on amd64"
.endif

# Beware, because gdbm is under GPL, you must treat the whole binary
# as GPL says if you include gdbm in it.
EXT_PORTS=	databases/ruby-bdb1
_PORTSDIR=	${.CURDIR}/../..
_RUBY_PORTDIR=	${_PORTSDIR}/${RUBY_PORT}

.if ${RUBY_VER} < 1.7
EXT_PORTS+=	${RUBY_SHIM18_PORT}
.else
EXT_PORTS+=	converters/ruby-iconv
.endif

.for p in ${EXT_PORTS}
EXTRACT_DEPENDS+=	${NONEXISTENT}:${_PORTSDIR}/${p}:patch
.endfor

GNU_CONFIGURE=	yes
USE_ICONV=	yes

WRKSRC=		${RUBY_WRKSRC}

DESCR=		${_RUBY_PORTDIR}/pkg-descr

# You can build a totally statically linked binary by defining STATIC,
# although the resulted interpreter is not capable of loading dynamic
# modules.

CONFIGURE_ENV=		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS!=	cd ${_RUBY_PORTDIR} && ${MAKE} -V CONFIGURE_ARGS
.if defined(STATIC)
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:N--enable-shared:M-*} \
			--with-static-linked-ext=yes \
			--with-opt-dir="${LOCALBASE}"
.else
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:M-*} \
			--with-opt-dir="${LOCALBASE}"
.endif

.if defined(DEBUG)
CFLAGS+=	-g
STRIP=		# none
.endif

MAKE_ARGS=	-j3

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT}

do-fetch:
	@${DO_NADA}

post-patch:
.if defined(STATIC)
	${RUBY} -i -pe 'gsub /-rdynamic/, "-static"' ${WRKSRC}/configure.in
.endif
	${RUBY} -i -pe '$$. == 1 and puts %q/require "rbconfig.rb"/' ${WRKSRC}/ext/bdb1/extconf.rb

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${_RUBY_PORTDIR} && ${MAKE} -V WRKSRC` ${WRKSRC}
.for p in ${EXT_PORTS}
	wrksrc=$$(cd ${_PORTSDIR}/${p} && ${MAKE} -V WRKSRC) ; \
	${FIND} -L $$wrksrc -name extconf.rb | \
	${XARGS} ${GREP} -l create_makefile | \
	while read extdir; do \
		extdir=$${extdir%/extconf.rb}; \
		case "$p" in \
		${RUBY_SHIM18_PORT}) \
			m=$$(basename $$extdir); \
			case $$extdir in \
			*/racc/*) \
				${MKDIR} ${WRKSRC}/ext/racc; \
				m=racc/$${m} ;; \
			*/ext/features/ruby18/*) \
				${MKDIR} ${WRKSRC}/ext/features/ruby18; \
				m=features/ruby18/$${m}_ruby18 ;; \
			esac ;; \
		*) \
			m="${p:T:S,^ruby-,,}" ;; \
		esac; \
		${CP} -RPp $$extdir ${WRKSRC}/ext/$$m; \
		${TOUCH} ${WRKSRC}/ext/$$m/MANIFEST; \
	done
.endfor
.if defined(STATIC)
	${ECHO_CMD} "option nodynamic" > ${WRKSRC}/ext/Setup
.else
	${ECHO_CMD} "#option nodynamic" > ${WRKSRC}/ext/Setup
.endif
	cd ${WRKSRC}/ext; ${FIND} * -name extconf.rb | \
	${XARGS} ${GREP} -l create_makefile | \
	while read extdir; do \
		extdir=$${extdir%/extconf.rb}; \
		echo $$extdir; \
	done >> Setup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${RUBY_NAME} ${RUBY_WITH_SUFFIX}_s
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	${LN} -fs ${RUBY_NAME}_s ${RUBY_WITHOUT_SUFFIX}_s
.endif

.include <bsd.port.post.mk>
