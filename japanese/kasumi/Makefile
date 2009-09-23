# New ports collection makefile for:	kasumi
# Date Created:				10 January 2005
# Whom:					MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kasumi
PORTVERSION=	2.5
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/41436

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A dictionary management tool for anthy

USE_GMAKE=	yes
USE_GNOME=	gnomehier gtk20
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		kasumi.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
