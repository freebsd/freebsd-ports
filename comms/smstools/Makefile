# New ports collection makefile for:   	smstools
# Date created:                        	06-11-2004
# Whom:                                	Benny Kjaergaard <bennyk@wax.dk>
#
# $FreeBSD$
#

PORTNAME=	smstools
PORTVERSION=	2.2.20
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://smstools.meinemullemaus.de/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to handle Short Message Service

LIB_DEPENDS=	mm:${PORTSDIR}/devel/mm

CONFLICTS=	gnokii-[0-9]* smstools-3.* sendsms-[0-9]*
NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_RC_SUBR=	smsd.sh
SPOOLDIR?=	/var/spool/sms
PLIST_SUB+=	PREFIX="${PREFIX}" \
		SPOOLDIR="${SPOOLDIR}"

DOCS=		alarmhandler.html blacklist.html book.html butterfly.gif \
		compiling.html configure.html configure2.html costs.html \
		email.gif eventhandler.html faq.html fileformat.html \
		gpl.html gpl_de.html hardwarecomp.html index.html \
		license.html links.html paypalbutton.gif raster.gif \
		references.html releasenotes.html run.html softwarecomp.html \
		statformat.html statusmonitor.html support.gif support.html \
		udh.html windows.html
EXAMPLES=	.procmailrc .qmailrc operator_logo1.sms operator_logo2.sms \
		received_report.sms received_sms.sms send_sms.sms \
		send_sms_unicode.sms smsd.conf.easy smsd.conf.full
SCRIPTS=	email2sms hex2bin hex2dec mysmsd sendsms sms sms2html \
		sms2unicode sms2xml smsevent smsresend sql_demo unicode2sms

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/install.sh ${WRKSRC}/src/smsd_cfg.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/examples/,} ${EXAMPLESDIR}/
.endif
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/scripts/,} ${PREFIX}/bin

.include <bsd.port.mk>
