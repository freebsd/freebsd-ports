# New ports collection makefile for: mingw32-bin-msvcrt
# Date created:		24 Oct 2002
# Whom:                 Lev A. Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	bin-msvcrt
PORTVERSION=	r${RUNTIMEVERSION}.a${APIVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mingw
PKGNAMEPREFIX=	mingw32-
DISTFILES=	mingw-runtime-${RUNTIMEVERSION}${EXTRACT_SUFX} \
		w32api-${APIVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	mingw

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Headers and Libraries for Windows cross-development

CONFLICTS=	mingw-bin-msvcrt-*

RUNTIMEVERSION=	3.3
APIVERSION=	2.5

NO_MTREE=	yes
NO_WRKSUBDIR=	yes

.if defined(INSTALL_AS_USER)
MAKE_ARGS+=	INSTALL_AS_USER=yes
.endif

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
