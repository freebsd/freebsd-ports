# New ports collection makefile for:	plgrenouille_0
# Date created:				02 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	plgrenouille
PORTVERSION=	0.61.5
CATEGORIES=	french net
MASTER_SITES=	ftp://blade.concept-micro.com/
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	cyrille.lefevre@laposte.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
SCRIPTS_ENV=	PKG_PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		plgrenouille.1
DOC_FILES=	FAQ README
RUN_DIR=	/var/run
LOG_DIR=	/var/log
SPOOL_DIR=	/var/spool/${PORTNAME}
SPOOL_USER=	daemon

post-patch: patch-script patch-pkgmessage

patch-script:
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|;s|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%RUN_DIR%%|${RUN_DIR}|;s|%%SPOOL_DIR%%|${SPOOL_DIR}|' \
		-e 's|%%LOG_DIR%%|${LOG_DIR}|;s|%%SPOOL_USER%%|${SPOOL_USER}|' \
		${WRKSRC}/plgrenouille.pl

patch-pkgmessage:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

do-install: install-script install-man install-data install-doc install-rc

install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/plgrenouille.pl \
		${PREFIX}/libexec/plgrenouille

install-man:
	@${INSTALL_MAN} ${WRKSRC}/plgrenouille.1 ${MAN1PREFIX}/man/man1

install-data:
	@${INSTALL_DATA} ${WRKSRC}/grenouillerc.sample ${PREFIX}/etc

install-doc:
.if !defined(NOPORTSDOC)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-rc:
	@${INSTALL_SCRIPT} ${FILESDIR}/plgrenouille.sh ${PREFIX}/etc/rc.d

post-install: display-message configure-package

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

configure-package:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
