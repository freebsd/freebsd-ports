# New ports collection makefile for:	p4p
# Date created:				3 Apr 2010
# Whom:					gordon@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4p
PORTVERSION=	2011.1.393975
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/r${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4p
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

P4CACHE?=	/var/db/p4p
P4LOG?=		/var/log/p4p.log

SUB_LIST=	P4CACHE=${P4CACHE} \
		P4LOG=${P4LOG}

USE_RC_SUBR=	p4p

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4p ${PREFIX}/sbin/

post-install:
	${MKDIR} ${DESTDIR}${P4CACHE}
	${CHOWN} p4admin:p4admin ${DESTDIR}${P4CACHE}
	${CHMOD} 750 ${DESTDIR}${P4CACHE}
	${TOUCH} ${DESTDIR}${P4LOG}
	${CHOWN} p4admin:p4admin ${DESTDIR}${P4LOG}
	${CHMOD} 640 ${DESTDIR}${P4LOG}
	@${ECHO_CMD} "@exec ${MKDIR} ${DESTDIR}${P4CACHE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${DESTDIR}${P4CACHE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 750 ${DESTDIR}${P4CACHE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${DESTDIR}${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${DESTDIR}${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 640 ${DESTDIR}${P4LOG}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
