# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.95.3
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	rskkserv/12167
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An alternative implementation of skkserv written in Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${SKKJISYO_BASE}/${SKKJISYO}:${SKK_MASTERDIR}

USE_RUBY=	yes
USE_AUTOCONF_VER=	213
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-ruby="${RUBY}" \
		--with-dicfile="${SKKJISYO_BASE}/${SKKJISYO}" \
		--with-cachedir="${SKKJISYO_BASE}" \
		--with-logdir="/var/log" \
		--with-piddir="/var/run"
MAKE_ARGS=	SKKSERV=rskkserv

SKKJISYO_SIZE?=	L
SKKJISYO_BASE=	${LOCALBASE}/share/skk
SKKJISYO=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/rskkserv.sh

MAN1=		rskkserv.1
MANLANG=	"" ja

DOCS_EN=	ChangeLog
DOCS_JA=	TODO

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
		${WRKSRC}/doc/rskkserv.conf.sample
	${RUBY} -i -p \
		-e 'sub %r%/usr/bin/ruby%, %q%${RUBY}% ' \
		${WRKSRC}/doc/conf-o2n.rb

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		( \
		${ECHO_CMD} "#!/bin/sh"; \
		${ECHO_CMD} "case \$$1 in"; \
		${ECHO_CMD} "start)"; \
		${ECHO_CMD} "	if [ -f ${PREFIX}/sbin/rskkserv ]; then"; \
		${ECHO_CMD} "		${ECHO_CMD} -n ' rskkserv: '"; \
		${ECHO_CMD} "		${PREFIX}/sbin/rskkserv"; \
		${ECHO_CMD} "	fi"; \
		${ECHO_CMD} "	;;"; \
		${ECHO_CMD} "stop)"; \
		${ECHO_CMD} "	pidfile=/var/run/rskkserv.pid"; \
		${ECHO_CMD} "	if [ -f \$$pidfile ]; then"; \
		${ECHO_CMD} "	    kill \`cat \$$pidfile\` && echo -n ' rskkserv'"; \
		${ECHO_CMD} "	    ${RM} -f \$$pidfile"; \
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
	${INSTALL_MAN} ${WRKSRC}/doc/rskkserv.1 ${PREFIX}/man/man1/rskkserv.1
	${INSTALL_MAN} ${WRKSRC}/doc/rskkserv.1.ja_JP.eucJP ${PREFIX}/man/ja/man1/rskkserv.1
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/conf-o2n.rb ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rskkserv.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rskkserv.conf.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
