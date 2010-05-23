# New ports collection makefile for: xmms-infopipe
# Date created:		14 July 2003
# Whom:			mig
#
# $FreeBSD$
#

PORTNAME=	xmms-infopipe
PORTVERSION=	1.3
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.beastwithin.org/users/wwwwolf/code/xmms/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create a named pipe to retrive xmms info about currently playing song

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LIBDIR?=	${PREFIX}/lib/xmms/General
SRCLIBDIR?=	src/.libs

PLIST_FILES=	lib/xmms/General/libinfopipe.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

do-install:
	cd ${WRKSRC}/${SRCLIBDIR};\
	${MKDIR} ${LIBDIR};\
	${INSTALL_PROGRAM} libinfopipe-1.3.so.1 ${LIBDIR}/libinfopipe.so

.include <bsd.port.mk>
