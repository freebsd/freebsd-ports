# New ports collection makefile for:	geepee32
# Date Created:				05 October 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	geepee32
PORTVERSION=	30
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	http://users.skynet.be/firefly/gp32/project/geepee32/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_linux_sdl_${PORTVERSION}

MAINTAINER=	arundel@gmx.net
COMMENT=	The only GP32 emulator for x86 archs

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_XLIB=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TARGET_DIR=	${PREFIX}/${PORTNAME}

do-install:
	${INSTALL} -d -m 777 ${TARGET_DIR}
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${TARGET_DIR}
	${INSTALL_SCRIPT} ${SCRIPTDIR}/${PORTNAME}.sh ${TARGET_DIR}

post-install:
	@${TOUCH} ${TARGET_DIR}/iic.bin
	@${LN} -s ${TARGET_DIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please don't mail us with requests for ROM dump."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
