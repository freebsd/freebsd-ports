# New ports collection makefile for:	rskkserv
# Date created:		18 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rskkserv
PORTVERSION=	2.90.1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.unixuser.org/~ysjj/rskkserv/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tcpwrap.so:${PORTSDIR}/security/ruby-tcpwrap \
		${LOCALBASE}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

USE_RUBY=	yes

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/rskkserv.sh
MAKE_ARGS=	prefix="${PREFIX}" \
		skkdicsize="${SKKJISYO_SIZE}" \
		epwdicbase="${PREFIX}/share/dict" \
		skkdicbase="${PREFIX}/share/skk" \
		SKKSERV=rskkserv

DOCS_EN=	ChangeLog
DOCS_JA=	README		TODO

post-patch:
	${MV} ${WRKSRC}/rskkserv.conf ${WRKSRC}/rskkserv.conf.in

post-install:
	${CP} -R ${WRKSRC}/skkserv ${RUBY_SITELIBDIR}/
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		${ECHO} 'case $$1 in' >> ${STARTUP_SCRIPT}; \
		${ECHO} "start)" >> ${STARTUP_SCRIPT}; \
		${ECHO} "	if [ -f ${PREFIX}/libexec/rskkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		${ECHO} "		${ECHO} -n ' rskkserv'; ${PREFIX}/libexec/rskkserv" >> \
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
