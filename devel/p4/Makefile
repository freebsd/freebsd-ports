# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4
PORTVERSION=	2014.2.1045032
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.freebsd100${ARCH:S,i386,x86,:S,amd64,x86_64,}/
DISTNAME=	p4
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce client

BROKEN_FreeBSD_8=	no distfiles
BROKEN_FreeBSD_9=	no distfiles
BROKEN_FreeBSD_11=	no distfiles

ONLY_FOR_ARCHS=	amd64 i386

P4VERSION=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${ARCH}

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/p4

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
