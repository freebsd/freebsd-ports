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

# Beware, we can't statically link the gdbm module because gdbm is GPL'ed.
EXT_PORTS=	archivers/ruby-zlib \
		devel/ruby-strscan \
		sysutils/ruby-syslog
_PORTSDIR=	${.CURDIR}/../..
_RUBY_PORTDIR=	${_PORTSDIR}/${RUBY_PORT}

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
			--with-libc_r=no \
			--with-opt-dir="${LOCALBASE}"

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
	${INSTALL_PROGRAM} ${WRKSRC}/${RUBY_NAME} ${RUBY}${_RUBY_SUFFIX}_s
	${LN} -fs ${RUBY}${_RUBY_SUFFIX}_s ${RUBY}_s

.include <bsd.port.post.mk>
