# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.94.0
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.unixuser.org/~ysjj/rskkserv/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${SKKJISYO_BASE}/${SKKJISYO}:${SKK_MASTERDIR}

USE_RUBY=	yes

USE_AUTOCONF=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-ruby="${RUBY}" \
		--with-dicfile="${SKKJISYO_BASE}/${SKKJISYO}" \
		--with-cachedir="${SKKJISYO_BASE}" \
		--with-logdir="/var/log" \
		--sbindir="${PREFIX}/libexec"

SKKJISYO_SIZE?=	L
SKKJISYO_BASE=	${LOCALBASE}/share/skk
SKKJISYO=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/rskkserv.sh
MAKE_ARGS=	SKKSERV=rskkserv

DOCS_EN=	ChangeLog
DOCS_JA=	README		TODO

post-patch:
	${RUBY} -i -p \
		-e 'gsub %r:/usr/share/skk:, %q:${SKKJISYO_BASE}:' \
		-e 'gsub %r:/opt/epwing/(\w+):, %q:${LOCALBASE}/share/dict/\\1-fpw:' \
		-e 'gsub %r:SKK-JISYO\\.L:, %q:${SKKJISYO}:' \
		-e 'sub %r%(CACHEDIR\s*=\s*")[^"]*(")%, \
					     %q%\\1${SKKJISYO_BASE}\\2%' \
		${WRKSRC}/rskkserv.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/rskkserv.conf.sample ${PREFIX}/etc/
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		( \
		${ECHO} "#!/bin/sh"; \
		${ECHO} 'case $$1 in'; \
		${ECHO} "start)"; \
		${ECHO} "	if [ -f ${PREFIX}/libexec/rskkserv ]; then"; \
		${ECHO} "		${ECHO} -n ' rskkserv';"; \
		${ECHO} "		if [ ${SKKJISYO_BASE}/${SKKJISYO} -nt ${SKKJISYO_BASE}/${SKKJISYO}.a ]; then"; \
		${ECHO} "			${ECHO} -n ' (updading index cache..)'; "; \
		${ECHO} "		fi; "; \
		${ECHO} "		${PREFIX}/libexec/rskkserv"; \
		${ECHO} "	fi"; \
		${ECHO} "	;;"; \
		${ECHO} "stop)"; \
		${ECHO} "	;;"; \
		${ECHO} "*)"; \
		${ECHO} '	${ECHO} "usage: $$0 {start|stop}" 1>&2'; \
		${ECHO} "	;;"; \
		${ECHO} 'esac'; \
		) > ${STARTUP_SCRIPT}; \
		${CHMOD} ${BINMODE} ${STARTUP_SCRIPT}; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/rskkserv/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rskkserv/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rskkserv/ja/
.endfor
.endif

.include <bsd.port.mk>
