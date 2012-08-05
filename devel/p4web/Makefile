# New ports collection makefile for:	p4web
# Date created:				3 Apr 2010
# Whom:					gordon@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4web
PORTVERSION=	2011.1.409868
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/r${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4web
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

P4LOG?=		/var/log/p4web.log

SUB_LIST=	P4LOG=${P4LOG}

USE_RC_SUBR=	p4web

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4web ${PREFIX}/sbin/

post-install:
	${TOUCH} ${DESTDIR}${P4LOG}
	${CHOWN} p4admin:p4admin ${DESTDIR}${P4LOG}
	${CHMOD} 640 ${DESTDIR}${P4LOG}
	@${ECHO_CMD} "@exec ${TOUCH} ${DESTDIR}${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${DESTDIR}${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 640 ${DESTDIR}${P4LOG}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
