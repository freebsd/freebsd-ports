# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4d
PORTVERSION=	2014.2.935585
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4d
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce server

RUN_DEPENDS=	p4:${PORTSDIR}/devel/p4

ONLY_FOR_ARCHS=	amd64 i386

P4VERSION=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}
DIST_SUBDIR=	perforce/${PORTVERSION}/bin.${PLATFORM}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${PLATFORM}

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

P4ROOT?=	/var/db/p4d
P4LOG?=		/var/log/p4d.log

SUB_LIST=	P4ROOT=${P4ROOT} \
		P4LOG=${P4LOG}

USE_RC_SUBR=	p4d

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4d ${STAGEDIR}${PREFIX}/sbin/
	@${MKDIR} ${STAGEDIR}${P4ROOT}
	@${ECHO_CMD} "@exec ${MKDIR} ${P4ROOT}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${P4ROOT}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 750 ${P4ROOT}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${P4ROOT} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 640 ${P4LOG}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
