# New ports collection makefile for:	libisc
# Date created:			26 Nov 2005
# Whom:				Simon L. Nielsen <simon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libisc
PORTVERSION=	9.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTNAME=	bind-${ISCVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	simon@FreeBSD.org
COMMENT=	ISC's utility library

DEPRECATED=	Unlikely to be used...
EXPIRATION_DATE=2010-11-07

# ISC releases things like 9.3.0rc1, which our versioning doesn't like
ISCVERSION=	9.3.1

GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes
BUILD_WRKSRC=	${WRKSRC}/lib/bind/freebsdportisc/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_LDCONFIG=	yes

MAN3=		assertions.3 eventlib.3 logging.3 tree.3 bitncmp.3 heap.3 \
		memcluster.3

.if defined(NO_PROFILE) || defined(NOPROFILE)
PLIST_SUB+=	PROFLIB="@comment "
.else
PLIST_SUB+=	PROFLIB=""
.endif

.include <bsd.port.mk>
