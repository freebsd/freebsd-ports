# New ports collection makefile for:	squeuer
# Date created:		6 August 2003
# Whom:			glewis@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	squeuer
PORTVERSION=	2.0.1
CATEGORIES=	astro net
MASTER_SITES=	http://www.eyesbeyond.com/squeuer/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A queueing proxy for Seti@Home

NO_BUILD=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes

# These must be writeable by the user "squeuer"
SPOOLDIR?=	/var/spool/squeuer
LOGDIR?=	/var/spool/squeuer
PIDDIR?=	/var/spool/squeuer

do-configure:
	for i in ${WRKSRC}/etc/squeuer.conf.unix ${WRKSRC}/etc/rc.d/S71squeuer.sh; do \
		${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" \
			-e "s:%%SPOOLDIR%%:${SPOOLDIR}:g" \
			-e "s:%%LOGDIR%%:${LOGDIR}:g" \
			-e "s:%%PIDDIR%%:${PIDDIR}:g" $$i; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/squeuer.pl ${PREFIX}/sbin/squeuer
	${INSTALL_DATA} ${WRKSRC}/etc/squeuer.conf.unix ${PREFIX}/etc/squeuer.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rc.d/S71squeuer.sh ${PREFIX}/etc/rc.d/squeuer.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${WRKSRC}/doc/TODO ${DOCSDIR}
.endif

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL
	if [ ! -e ${SPOOLDIR} ]; then \
		${MKDIR} ${SPOOLDIR}; \
		${CHOWN} squeuer:squeuer ${SPOOLDIR}; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
