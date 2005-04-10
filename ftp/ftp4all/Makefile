# New ports collection makefile for:	ftp4all
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	ftp4all
PORTVERSION=	3.012
CATEGORIES=	ftp
MASTER_SITES=	http://www.ftp4all.de/v3/archives/ \
		http://www.ftp4all.de/v3/
DISTNAME=	ftpd-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} f4awebsite.tar.gz

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Advanced ftp-daemon

HAS_CONFIGURE=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ENV=	WANT_DES=y
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG} "-------------------------------------------------"
	@${ECHO_MSG}
	@${ECHO_MSG} "You can automate configuration process by setting"
	@${ECHO_MSG} "environment variable WANT_DES to 'y' or 'n'"
	@${ECHO_MSG}
	@${ECHO_MSG} "-------------------------------------------------"
	@${ECHO_MSG}
.endif

DISTCFGPATH=	${WRKSRC}/standard/etc
CFGPATH=	${PREFIX}/etc/ftp4all
DISTMSGPATH=	${WRKSRC}/standard/msg
MSGPATH=	${PREFIX}/etc/ftp4all/msg

.include <bsd.port.pre.mk>

do-install:
	-@${MKDIR} /var/log/ftp4all
	-@${MKDIR} ${PREFIX}
	-@${MKDIR} ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftpd ${PREFIX}/sbin/f4a.ftpd
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftps ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftpa ${PREFIX}/sbin/
	-@${MKDIR} ${CFGPATH}
	${INSTALL_DATA} ${DISTCFGPATH}/cdpath.cfg ${CFGPATH}/cdpath.cfg.sample
	${INSTALL_DATA} ${DISTCFGPATH}/check.cfg ${CFGPATH}/check.cfg.sample
	${INSTALL_DATA} ${DISTCFGPATH}/checkdupe.cfg ${CFGPATH}/checkdupe.cfg.sample
	${INSTALL_DATA} ${DISTCFGPATH}/dirshortcut.cfg ${CFGPATH}/dirshortcut.cfg.sample
	${INSTALL_DATA} ${DISTCFGPATH}/ftpd.reg ${CFGPATH}/ftpd.reg.sample
	${INSTALL_DATA} ${DISTCFGPATH}/limits.cfg ${CFGPATH}/limits.cfg.sample
	-@${MKDIR} ${MSGPATH}
	-@${MKDIR} ${MSGPATH}/usr
	-@${MKDIR} ${MSGPATH}/grp
	${INSTALL_DATA} ${DISTMSGPATH}/goodbye ${MSGPATH}/goodbye.sample
	${INSTALL_DATA} ${DISTMSGPATH}/startup ${MSGPATH}/startup.sample
	${INSTALL_DATA} ${DISTMSGPATH}/welcome ${MSGPATH}/welcome.sample
	${INSTALL_DATA} ${DISTMSGPATH}/who_body ${MSGPATH}/who_body.sample
	${INSTALL_DATA} ${DISTMSGPATH}/who_tail ${MSGPATH}/who_tail.sample
	${INSTALL_DATA} ${DISTMSGPATH}/who_top ${MSGPATH}/who_top.sample
	-@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/RELEASE-TEXT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/VERSION ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/ftp4all.gif ${DOCSDIR}
	${CP} -pPRf ${WRKDIR}/f4adp ${DOCSDIR}
	${CP} -pPRf ${WRKDIR}/frames ${DOCSDIR}
	${CP} -pPRf ${WRKDIR}/noframes ${DOCSDIR}
	-@${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${FILESDIR}/ftp4all.sh ${PREFIX}/etc/rc.d/ftp4all.sh.sample

.include <bsd.port.post.mk>
