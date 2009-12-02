# New ports collection makefile for:   	smstools3
# Date created:                        	2008-05-18
# Whom:                                	Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smstools
PORTVERSION=	3.1.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://smstools3.kekekasvi.com/packages/
DISTNAME=	smstools3-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	SMS Gateway software for GSM modems and mobile phones

CONFLICTS=	gnokii-[0-9]* smstools-2.* sendsms-[0-9]*
OPTIONS=	STATS "Build status and statistics support" on

WRKSRC=		${WRKDIR}/smstools3
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_RC_SUBR=	smsd
SPOOLDIR?=	/var/spool/sms
LOGDIR?=	/var/log/smsd
PIDDIR?=	/var/run/smsd
SMSD_USER?=	uucp
SMSD_GROUP?=	dialer
SUB_LIST+=	SPOOLDIR="${SPOOLDIR}" LOGDIR="${LOGDIR}" PIDDIR="${PIDDIR}" \
		SMSD_USER="${SMSD_USER}" SMSD_GROUP="${SMSD_GROUP}"
PLIST_SUB+=	SPOOLDIR="${SPOOLDIR}" LOGDIR="${LOGDIR}" PIDDIR="${PIDDIR}" \
		SMSD_USER="${SMSD_USER}" SMSD_GROUP="${SMSD_GROUP}"

DOCS=		blacklist.html book.html compiling.html \
		configure.html configure2.html eventhandler.html \
		faq.html fileformat.html gpl.html hardwarecomp.html \
		history3.html index.html license.html localizing.html \
		run.html statusmonitor.html udh.html windows.html

SLIDESHOW=	blacklist.gif eventhandler.gif logfile.gif modem.gif \
		move_l.gif move_r.gif page1.html page2.html page2.jpg \
		page2b.html page3.html page4.html page5.html page6.html \
		page7.html page8.html queue.gif sms.gif smstools3-small.jpg \
		statistic.gif status.gif

EXAMPLES=	.procmailrc .qmailrc language-ISO-8859-15.fi \
		language-UTF-8.fi operator_logo1.sms operator_logo2.sms \
		received_report.sms received_sms.sms send_sms.sms \
		send_sms_unicode.sms smsd.conf.easy smsd.conf.full \
		smsd.conf.non-root

SCRIPTS=	checkhandler-utf-8 email2sms eventhandler-utf-8 forwardsms \
		hex2bin hex2dec mysmsd pkill regular_run sendsms sms2html \
		sms2unicode sms2xml sms3 smsevent smsresend smstest.php \
		sql_demo unicode2sms

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_STATS)
LIB_DEPENDS+=	mm.14:${PORTSDIR}/devel/mm
CFLAGS+=	-I${LOCALBASE}/include
.else
CFLAGS+=	-DNOSTATS
.endif
.if ${OSVERSION} < 800045
SMSTOOLS_DEFAULT_COMPORT?= /dev/cuad0
.else
SMSTOOLS_DEFAULT_COMPORT?= /dev/cuau0
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile \
		${WRKSRC}/install.sh ${WRKSRC}/src/smsd_cfg.c
	@${REINPLACE_CMD} 's|/dev/ttyS0|${SMSTOOLS_DEFAULT_COMPORT}|g' \
		${WRKSRC}/examples/smsd.conf.easy \
		${WRKSRC}/examples/smsd.conf.full \
		${WRKSRC}/examples/smsd.conf.non-root

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/scripts/,} ${DATADIR}
.for FILE in sendsms sms2html sms2unicode unicode2sms
	@${LN} -sf ${DATADIR}/${FILE} ${PREFIX}/bin/${FILE}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/examples/smsd.conf.easy ${PREFIX}/etc/smsd.conf.sample
	@if [ ! -f ${PREFIX}/etc/smsd.conf ]; then \
		${CP} ${PREFIX}/etc/smsd.conf.sample ${PREFIX}/etc/smsd.conf; \
	fi
	@${MKDIR} ${SPOOLDIR} ${LOGDIR} ${PIDDIR}
	@${CHOWN} -R ${SMSD_USER}:${SMSD_GROUP} ${SPOOLDIR} ${LOGDIR} ${PIDDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/slideshow
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
	@${INSTALL_DATA} ${SLIDESHOW:S,^,${WRKSRC}/doc/slideshow/,} \
		${DOCSDIR}/slideshow
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}/
.endif
.include <bsd.port.post.mk>
