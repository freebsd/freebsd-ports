# New ports collection makefile for:	xmms-xymms
# Date created:				27 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xymms
DISTVERSION=	0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Sega Genesis GYM plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	gtk12

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

PLIST_FILES=	lib/xmms/Input/libxymms.so %%EXAMPLESDIR%%/sample.gym
PLIST_DIRS=	%%EXAMPLESDIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT||' ${WRKSRC}/src/Makefile.in

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/sample.gym ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
