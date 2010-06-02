# New ports collection makefile for:	plgrenouille_0
# Date created:				02 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	plgrenouille
PORTVERSION=	0.70.6
PORTREVISION=	7
CATEGORIES=	french net
MASTER_SITES=	http://concept.free.free.fr/plgrenouille/beta/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Un client pour determiner votre bande passante a un raccordement large bande

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

NO_BUILD=	yes
USE_PERL5=	yes
USE_RC_SUBR=	plgrenouille.sh
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
PKGDEINSTALL=	${PKGINSTALL}
PLIST_SUB=	LBIN_DIR="${LBIN_DIR:S,^${PREFIX}/,,}" \
		CONF_DIR="${CONF_DIR:S,^${PREFIX}/,,}"
REINPLACE_SUB=	PREFIX=${PREFIX} PERL=${PERL} \
		LBIN_DIR=${LBIN_DIR} CONF_DIR=${CONF_DIR} \
		RUN_DIR=${RUN_DIR} LOG_DIR=${LOG_DIR} \
		SPOOL_DIR=${SPOOL_DIR} SPOOL_USER=${SPOOL_USER}
SUB_FILES=	pkg-message
SUB_LIST=	LBIN_DIR=${LBIN_DIR} RUN_DIR=${RUN_DIR} LOG_DIR=${LOG_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

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

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/plgrenouille.pl ${WRKSRC}/Grenouille/Vars.pm
	@${REINPLACE_CMD} 's!swap_privileges!Grenouille::System::&!g' \
		${WRKSRC}/Grenouille/Log.pm ${WRKSRC}/Grenouille/Preferences.pm

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/plgrenouille.pl \
		${LBIN_DIR}/plgrenouille
	@${MKDIR} ${SITE_PERL}/Grenouille
	@${INSTALL_SCRIPT} ${WRKSRC}/Grenouille/*.pm \
		${SITE_PERL}/Grenouille
	@${INSTALL_MAN} ${WRKSRC}/plgrenouille.1 ${MAN_DIR}
	@${INSTALL_DATA} ${WRKSRC}/grenouillerc.sample ${CONF_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
