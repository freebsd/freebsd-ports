# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.94.12a
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.unixuser.org/~ysjj/rskkserv/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An alternative implementation of skkserv written in Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${SKKJISYO_BASE}/${SKKJISYO}:${SKK_MASTERDIR}

USE_RUBY=	yes

USE_AUTOCONF=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-ruby="${RUBY}" \
		--with-dicfile="${SKKJISYO_BASE}/${SKKJISYO}" \
		--with-cachedir="${SKKJISYO_BASE}" \
		--with-logdir="/var/log" \
		--with-piddir="/var/run" \
		--sbindir="${PREFIX}/libexec"
MAKE_ARGS=	SKKSERV=rskkserv

SKKJISYO_SIZE?=	L
SKKJISYO_BASE=	${LOCALBASE}/share/skk
SKKJISYO=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/rskkserv.sh

DOCS_EN=	ChangeLog
DOCS_JA=	README		TODO

post-extract:
	${LN} -s ${WRKSRC}/skkserv.rb.in ${WRKSRC}/rskkserv.in

post-patch:
	${RUBY} -i -ne 'if $$. == 1 then puts "#!@RUBY@" else puts $$_ end' ${WRKSRC}/skkserv.rb.in
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
		${ECHO_CMD} "#!/bin/sh"; \
		${ECHO_CMD} "case \$$1 in"; \
		${ECHO_CMD} "start)"; \
		${ECHO_CMD} "	if [ -f ${PREFIX}/libexec/rskkserv ]; then"; \
		${ECHO_CMD} "		${ECHO_CMD} -n ' rskkserv: '"; \
		${ECHO_CMD} "		${PREFIX}/libexec/rskkserv"; \
		${ECHO_CMD} "	fi"; \
		${ECHO_CMD} "	;;"; \
		${ECHO_CMD} "stop)"; \
		${ECHO_CMD} "	pidfile=/var/run/rskkserv.pid"; \
		${ECHO_CMD} "	if [ -f \$$pidfile ]; then"; \
		${ECHO_CMD} "	    kill \`cat \$$pidfile\` && echo -n ' rskkserv'"; \
		${ECHO_CMD} "	    ${RM} \$$pidfile"; \
		${ECHO_CMD} "	else"; \
		${ECHO_CMD} "	    ${ECHO_CMD} ' rskkserv: not running'"; \
		${ECHO_CMD} "	fi"; \
		${ECHO_CMD} "	;;"; \
		${ECHO_CMD} "*)"; \
		${ECHO_CMD} "	${ECHO_CMD} \"usage: \$$0 {start|stop}\" 1>&2"; \
		${ECHO_CMD} "	;;"; \
		${ECHO_CMD} "esac"; \
		) > ${STARTUP_SCRIPT}; \
		${CHMOD} ${BINMODE} ${STARTUP_SCRIPT}; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
