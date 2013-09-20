# Created by: <arundel@gmx.net>
# $FreeBSD$

PORTNAME=	geepee32
PORTVERSION=	30
PORTREVISION=	3
CATEGORIES=	emulators linux
MASTER_SITES=	http://users.skynet.be/firefly/gp32/project/geepee32/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_linux_sdl_${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	The only GP32 emulator for i386

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 xorglibs
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
REINPLACE_ARGS=

TARGET_DIR=	${PREFIX}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD}-e 's|%%GEEPEE32DIR%%|${PREFIX}/${PORTNAME}|' ${SCRIPTDIR}/wrapper.sh > \
	${WRKDIR}/wrapper.sh

do-install:
	${INSTALL} -d -m 777 ${TARGET_DIR}
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${TARGET_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${TARGET_DIR}/${PORTNAME}.sh

post-install:
	@${TOUCH} ${TARGET_DIR}/iic.bin
	@${LN} -s ${TARGET_DIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please don't mail us with requests for ROM dumps."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
