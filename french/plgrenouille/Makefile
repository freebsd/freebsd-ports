# New ports collection makefile for:	plgrenouille_0
# Date created:				02 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	plgrenouille
PORTVERSION=	0.70.6
PORTREVISION=	1
CATEGORIES=	french net
MASTER_SITES=	http://concept.free.free.fr/plgrenouille/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	Un client pour determiner votre bande passante a un raccordement large bande

LIB_DEPENDS=	netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP3
.else
RUN_DEPENDS+=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
.endif

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${PKGINSTALL}
PLIST_SUB=	LBIN_DIR="${LBIN_DIR:S,^${PREFIX}/,,}" \
		CONF_DIR="${CONF_DIR:S,^${PREFIX}/,,}" \
		RC_DIR="${RC_DIR:S,^${PREFIX}/,,}"
REINPLACE_SUB=	PREFIX=${PREFIX} PERL=${PERL} \
		LBIN_DIR=${LBIN_DIR} CONF_DIR=${CONF_DIR} \
		RUN_DIR=${RUN_DIR} LOG_DIR=${LOG_DIR} \
		SPOOL_DIR=${SPOOL_DIR} SPOOL_USER=${SPOOL_USER}
RCSCRIPTS_SUB=	${REINPLACE_SUB} RC_SUBR=${RC_SUBR}
PKGMESSAGE_SUB=	PREFIX=${PREFIX}

MAN1=		plgrenouille.1
DOC_FILES=	FAQ README
LBIN_DIR=	${PREFIX}/libexec
MAN_DIR=	${MAN1PREFIX}/man/man1
CONF_DIR=	${PREFIX}/etc
RC_DIR=		${PREFIX}/etc/rc.d
RUN_DIR=	/var/run
LOG_DIR=	/var/log
SPOOL_DIR=	/var/spool/${PORTNAME}
SPOOL_USER=	daemon

post-patch: patch-script patch-lib patch-rc patch-pkgmessage

patch-script:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/plgrenouille.pl ${WRKSRC}/Grenouille/Vars.pm

patch-lib:
	@${REINPLACE_CMD} 's!swap_privileges!Grenouille::System::&!g' \
		${WRKSRC}/Grenouille/Log.pm ${WRKSRC}/Grenouille/Preferences.pm

patch-rc:
	@${SED} ${RCSCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/plgrenouille.sh > ${WRKDIR}/plgrenouille.sh

patch-pkgmessage:
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}

do-install: install-script install-lib install-man \
		install-data install-doc install-rc

install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/plgrenouille.pl \
		${LBIN_DIR}/plgrenouille

install-lib:
	@${MKDIR} ${SITE_PERL}/Grenouille
	@${INSTALL_SCRIPT} ${WRKSRC}/Grenouille/*.pm \
		${SITE_PERL}/Grenouille

install-man:
	@${INSTALL_MAN} ${WRKSRC}/plgrenouille.1 ${MAN_DIR}

install-data:
	@${INSTALL_DATA} ${WRKSRC}/grenouillerc.sample ${CONF_DIR}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-rc:
	@${INSTALL_SCRIPT} ${WRKDIR}/plgrenouille.sh ${RC_DIR}

post-install: display-message configure-package

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

configure-package:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
