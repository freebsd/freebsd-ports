# New ports collection makefile for:    gnustep-guile
# Date created:         24 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-guile
PORTVERSION=	1.1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs

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
PKGNAMESUFFIX?=		-nox11
USE_GNUSTEP_BASE=	yes
PLIST_SUB+=		USEX11="@comment "
.else
USE_GNUSTEP_BACK=	yes
PLIST_SUB+=		USEX11=""
.endif

.include <bsd.port.pre.mk>

GUILE_VER!=	(cd ${PORTSDIR}/lang/guile && make -V GUILE_VER)

pre-configure:
	${TOUCH} ${WRKSRC}/Greg/ac_nonexistent.h

.if defined(WITH_GNUSTEP_DEVEL)
post-configure:
	${MKDIR} ${WRKSRC}/ScriptKit/Foundation
	${CP} ${FILESDIR}/NSConcreteNumber.h ${WRKSRC}/ScriptKit/Foundation/
.endif

.include <bsd.port.post.mk>
