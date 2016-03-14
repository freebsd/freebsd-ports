# Created by: joes@seaport.net
# $FreeBSD$

PORTNAME=	qpage
PORTVERSION=	3.3
PORTREVISION=	8
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
MASTER_SITES=	http://tomiii.com/qpage/qpage.org/download/

MAINTAINER=	rand@iteris.com
COMMENT=	SNPP client/server for sending messages to an alphanumeric pager

USES=tar:Z
USE_RC_SUBR=	qpage
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	IDENT_PATCH
IDENT_PATCH_DESC=	Disable libwrap ident lookups

IDENT_PATCH_EXTRA_PATCHES=${FILESDIR}/libwrap_ident_patch-srvrsnpp.c

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qpage.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/qpage.1
	${INSTALL_DATA} ${WRKSRC}/example.cf \
		${STAGEDIR}${PREFIX}/etc/qpage.conf.sample
	${MKDIR} ${STAGEDIR}/var/spool/qpage

.include <bsd.port.mk>
