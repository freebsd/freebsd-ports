# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.3
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.ruby-lang.org/~shugo/rskkserv/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_LIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${LOCALBASE}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}
RUBY_LIBDIR=	${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/rskkserv.sh
MAKE_ARGS=	prefix="${PREFIX}" \
		dicfile="${LOCALBASE}/share/skk/${SKKJISYO}"

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skkserv.rb ${PREFIX}/sbin/rskkserv
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		${ECHO} 'case $$1 in' >> ${STARTUP_SCRIPT}; \
		${ECHO} "start)" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	if [ -f ${PREFIX}/sbin/rskkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "		${ECHO} -n ' rskkserv'; ${PREFIX}/sbin/rskkserv" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "	fi" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} "stop)" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} "*)" >> ${STARTUP_SCRIPT}; \
		${ECHO} '	${ECHO} "usage: $$0 {start|stop}" 1>&2' >> ${STARTUP_SCRIPT}; \
		${ECHO} "	;;" >> ${STARTUP_SCRIPT}; \
		${ECHO} 'esac' >> ${STARTUP_SCRIPT}; \
		${CHMOD} ${BINMODE} ${STARTUP_SCRIPT}; \
	fi

.include <bsd.port.mk>
