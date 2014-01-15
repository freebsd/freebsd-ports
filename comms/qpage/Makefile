# Created by: joes@seaport.net
# $FreeBSD$

PORTNAME=	qpage
PORTVERSION=	3.3
PORTREVISION=	7
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jfb@mr-happy.com
COMMENT=	SNPP client/server for sending messages to an alphanumeric pager

USE_RC_SUBR=	qpage
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	IDENT_PATCH
IDENT_PATCH_DESC=	Disable libwrap ident lookups

MAN1=		qpage.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDENT_PATCH}
EXTRA_PATCHES=${FILESDIR}/libwrap_ident_patch-srvrsnpp.c
.endif

.if !defined(WITH_QPAGE_SYSLOG_FACILITY) || !defined(WITH_QPAGE_USER)
.if !defined(WITH_QPAGE_SYSLOG_FACILITY) && !defined(WITH_QPAGE_USER)
_QPAGE_MSG=	You may set the following configuration options:
.else
_QPAGE_MSG=	The following additional configuration options are available:
.endif
.if !defined(WITH_QPAGE_SYSLOG_FACILITY)
WITH_QPAGE_SYSLOG_FACILITY=	LOG_DAEMON
_QPAGE_SYSLOG_MSG=1
.endif
.if !defined(WITH_QPAGE_USER)
WITH_QPAGE_USER=	uucp
_QPAGE_USER_MSG=1
.endif
pre-patch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} ${_QPAGE_MSG}
	@if [ -n "${_QPAGE_SYSLOG_MSG}" ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "  WITH_QPAGE_SYSLOG_FACILITY=syslog_facility"; \
		${ECHO_MSG} "      Default is LOG_DAEMON"; \
	fi
	@if [ -n "${_QPAGE_USER_MSG}" ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "  WITH_QPAGE_USER=userid"; \
		${ECHO_MSG} "      Default is \"uucp\"; recommended that user be in group \"dialer\""; \
	fi
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press ^C now to stop the build and set make options."
	@${ECHO_MSG} "You may find it necessary to 'make clean' before restarting the build."
	@sleep 2
.endif

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/qpage.man \
		${WRKSRC}/config.input \
		${WRKSRC}/config.h.in
	${REINPLACE_CMD} \
		-e 's,%%WITH_QPAGE_SYSLOG_FACILITY%%,${WITH_QPAGE_SYSLOG_FACILITY},' \
		-e 's,%%WITH_QPAGE_USER%%,${WITH_QPAGE_USER},' \
		${WRKSRC}/config.input

post-install:
	@if [ ! -f ${PREFIX}/etc/qpage-example.cf ]; then \
		${ECHO_MSG} "Install ${PREFIX}/etc/qpage-example.cf file."; \
		${INSTALL_DATA} -m 640 ${WRKDIR}/${PORTNAME}-${PORTVERSION}/example.cf \
			${PREFIX}/etc/qpage-example.cf; \
	fi
	${MKDIR} /var/spool/${PORTNAME}
	${CHOWN} ${WITH_QPAGE_USER}:dialer /var/spool/${PORTNAME}
	${CHMOD} 0775 /var/spool/${PORTNAME}

.include <bsd.port.mk>
