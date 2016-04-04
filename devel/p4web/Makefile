# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4web
PORTVERSION=	2012.1.732581
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://swarm.workshop.perforce.com/download/guest/perforce_software/p4web/bin/${P4VERSION}/bin.${PLATFORM}/
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

# 10.x (and higher) needs compat libs
.if ${OSVERSION} >= 1000054
LIB_DEPENDS+=	libstdc++.so.6:misc/compat9x
.endif

# Figure out what to install
.if ${ARCH} == amd64
PLATFORM=	freebsd70x86_64
.elif ${ARCH} == i386
PLATFORM=	freebsd70x86
.else
IGNORE=		unsupported OS release, sorry
.endif

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4web ${STAGEDIR}${PREFIX}/sbin/

post-install:
	@${ECHO_CMD} "@exec ${TOUCH} ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} p4admin:p4admin ${P4LOG}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 640 ${P4LOG}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
