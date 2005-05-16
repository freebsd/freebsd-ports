# New ports collection makefile for:  pstngw
# Date created:         Wed Apr 15 15:41:00 GMT 2000
# Whom:                 Jakub Klausa <jacke@bofh.pl>
#
# $FreeBSD$
#

PORTNAME=	pstngw
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.openh323.org/bin/
DISTNAME=	pstngw_${PORTVERSION}

MAINTAINER=	jacke@bofh.pl
COMMENT=	Simple H.323-PSTN (POTS) gateway

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

NOCLEANDEPENDS=	yes

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/pstngw
MAKE_ENV+=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../../net/openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}

PLIST_FILES=	bin/pstngw

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (shared libraries must be compiled with -fPIC)"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_d/pstngw ${PREFIX}/bin

.include <bsd.port.post.mk>
