# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4ftpd
PORTVERSION=	2014.2.935585
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/r${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4ftpd
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce server

ONLY_FOR_ARCHS=	amd64 i386

P4VERSION=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}
DIST_SUBDIR=	perforce/${PORTVERSION}/bin.${PLATFORM}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${PLATFORM}

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

P4LOG?=		/var/log/p4ftpd.log

SUB_LIST=	P4LOG=${P4LOG}

USE_RC_SUBR=	p4ftpd

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4ftpd ${STAGEDIR}${PREFIX}/sbin/
	@${ECHO_CMD} "@exec ${TOUCH} ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 640 ${P4LOG}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
