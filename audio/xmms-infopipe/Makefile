# New ports collection makefile for: xmms-infopipe
# Date created:		14 July 2003
# Whom:			mig
#
# $FreeBSD$
#

PORTNAME=	xmms-infopipe
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.beastwithin.org/users/wwwwolf/code/xmms/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mig@mig-29.net
COMMENT=	Create a named pipe to retrive xmms info about currently playing song

RUN_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LIBDIR?=	${PREFIX}/lib/xmms/General
SRCLIBDIR?=	src/.libs

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%X11BASE%%/lib/xmms/General
PLIST_FILES=	lib/xmms/General/libinfopipe.so

do-install:
	cd ${WRKSRC}/${SRCLIBDIR};\
	${MKDIR} ${LIBDIR};\
	${INSTALL_PROGRAM} libinfopipe-1.3.so.1 ${LIBDIR}/libinfopipe.so

.include <bsd.port.mk>
