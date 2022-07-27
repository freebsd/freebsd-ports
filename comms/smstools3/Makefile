PORTNAME=	smstools
PORTVERSION=	3.1.21
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://smstools3.kekekasvi.com/packages/
DISTNAME=	smstools3-${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	SMS Gateway software for GSM modems and mobile phones

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		gmake localbase:ldflags shebangfix
CONFLICTS_INSTALL=	gnokii sendsms # bin/sendsms
WRKSRC=		${WRKDIR}/smstools3
SHEBANG_FILES=	scripts/eventhandler_report \
		scripts/hex2bin \
		scripts/hex2dec \
		scripts/load_balancing.sh \
		scripts/regular_run \
		scripts/sendsms \
		scripts/sms2html \
		scripts/sms2unicode \
		scripts/unicode2sms
SHEBANG_LANG=	awk
awk_OLD_CMD=	/bin/gawk
awk_CMD=	${LOCALBASE}/bin/awk
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
SUB_FILES=	pkg-message

CFLAGS+=	-fcommon
LDFLAGS+=	-linotify

PORTDOCS=	*
PORTEXAMPLES=	.procmailrc .qmailrc *

OPTIONS_DEFINE=	STATS UTF8 EXAMPLES DOCS
OPTIONS_DEFAULT=	STATS UTF8

STATS_DESC=	Build status and statistics support
STATS_LIB_DEPENDS=	libmm.so:devel/mm
STATS_CFLAGS_OFF=	-DNOSTATS

UTF8_USES=		iconv
UTF8_LDFLAGS=		-L${ICONV_PREFIX}/lib ${ICONV_LIB}
UTF8_CFLAGS=		-DUSE_ICONV

SMSTOOLS_DEFAULT_COMPORT?=	/dev/cuau0

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			-e 's|%%STAGEDIR%%|${STAGEDIR}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/install.sh ${WRKSRC}/src/smsd_cfg.h
	@${REINPLACE_CMD} -e 's|/dev/ttyS0|${SMSTOOLS_DEFAULT_COMPORT}|g' \
			-e 's|%%SMSD_USER%%|${SMSD_USER}|' \
			-e 's|%%SMSD_GROUP%%|${SMSD_GROUP}|' \
		${WRKSRC}/examples/smsd.conf.easy \
		${WRKSRC}/examples/smsd.conf.full \
		${WRKSRC}/examples/smsd.conf.non-root

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/smsd
	${MKDIR} ${STAGEDIR}${DATADIR}
	for file in `${FIND} ${WRKSRC}/scripts -type f ! -name 'README' ! -name '*.bak'`; do \
		${INSTALL_SCRIPT} $$file ${STAGEDIR}${DATADIR}/; \
	done
.for FILE in sendsms sms2html sms2unicode unicode2sms
	${RLN} ${STAGEDIR}${DATADIR}/${FILE} ${STAGEDIR}${PREFIX}/bin/${FILE}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/smsd.conf.easy ${STAGEDIR}${PREFIX}/etc/smsd.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}/slideshow
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/slideshow/* ${STAGEDIR}${DOCSDIR}/slideshow
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for file in `${FIND} ${WRKSRC}/examples -type f ! -name 'README'`; do \
		${INSTALL_SCRIPT} $$file ${STAGEDIR}${EXAMPLESDIR}/; \
	done
	${MKDIR} ${STAGEDIR}${SPOOLDIR}/incoming ${STAGEDIR}${SPOOLDIR}/outgoing \
		${STAGEDIR}${SPOOLDIR}/checked ${STAGEDIR}${LOGDIR} \
		${STAGEDIR}${PIDDIR}

.include <bsd.port.mk>
