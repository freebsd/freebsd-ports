# New ports collection makefile for:    gnustep-guile
# Date created:         24 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-guile
PORTVERSION=	1.1.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
PKGNAMESUFFIX?=	${NOX11_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep interface to the GUILE scheme interpreter

LIB_DEPENDS+=	guile.15:${PORTSDIR}/lang/guile

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
PLIST_SUB+=	GUILE_VER="${GUILE_VER}"

MAN1=	greg.1

.if defined(WITHOUT_X11)
NOX11_SUFFIX?=	-nox11
USE_GNUSTEP_BASE=	yes
PLIST_SUB+=		USEX11="@comment "
CONFLICTS?=		gnustep-guile-1.*
.else
USE_GNUSTEP_BACK=	yes
PLIST_SUB+=		USEX11=""
CONFLICTS?=		gnustep-guile-nox11-1.*
.endif

.include <bsd.port.pre.mk>

GUILE_VER!=	(cd ${PORTSDIR}/lang/guile && make -V GUILE_VER)

pre-configure:
	${TOUCH} ${WRKSRC}/Greg/ac_nonexistent.h

.include <bsd.port.post.mk>
