# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4p
PORTVERSION=	2015.1.1384697
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4p
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce server

RUN_DEPENDS=	p4:devel/p4

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

P4CACHE?=	/var/db/p4p
P4LOG?=		/var/log/p4p.log

PLIST_SUB=	P4CACHE=${P4CACHE}

SUB_LIST=	P4CACHE=${P4CACHE} \
		P4LOG=${P4LOG}

USE_RC_SUBR=	p4p

.include <bsd.port.pre.mk>

.include "${.CURDIR}/../p4/Makefile.inc"

USERS=	p4admin
GROUPS=	p4admin

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4p ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${P4CACHE}

.include <bsd.port.post.mk>
