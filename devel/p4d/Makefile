# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4d
PORTVERSION=	2016.1.1461251
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4d
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce server

RUN_DEPENDS=	p4:devel/p4

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

P4ROOT?=	/var/db/p4d
P4LOG?=		/var/log/p4d.log

PLIST_SUB=	P4ROOT=${P4ROOT}

SUB_LIST=	P4ROOT=${P4ROOT} \
		P4LOG=${P4LOG}

USE_RC_SUBR=	p4d

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4d ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${P4ROOT}

.include <bsd.port.post.mk>
