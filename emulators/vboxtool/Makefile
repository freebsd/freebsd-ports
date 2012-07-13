# New ports collection makefile for:	oneko
# Date created:        14 December 2012
# Whom:                pjm
#
# $FreeBSD$
#

PORTNAME=	vboxtool
PORTVERSION=	0.5
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	pierrejacques.mimifir@gmail.com
COMMENT=	Provides effective control of VirtualBox machines

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	VBoxManage:${PORTSDIR}/emulators/virtualbox-ose\
		bash:${PORTSDIR}/shells/bash

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

GROUPS=		vboxusers
USE_ZIP=	yes

SAMPLESDIR=	${PREFIX}/share/${PORTNAME}

do-install:
	@if  [ ! -f ${PREFIX}/etc/${PORTNAME} ]; then \
		${MKDIR}  	${PREFIX}/etc/${PORTNAME};\
	fi
	${MKDIR}  	${EXAMPLESDIR}
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/vboxtool.conf ]; then \
		${INSTALL_DATA} 	${FILESDIR}/vboxtool.conf	${PREFIX}/etc/${PORTNAME}/vboxtool.conf;\
	fi
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/machines.conf ]; then \
		${INSTALL_DATA} 	${FILESDIR}/machines.conf	${PREFIX}/etc/${PORTNAME}/machines.conf;\
	fi
	${INSTALL_SCRIPT} -m 0750	${WRKSRC}/script/vboxtool		${PREFIX}/bin/vboxtool
	${INSTALL_SCRIPT} -m 0750	${WRKSRC}/script/vboxtoolinit		${PREFIX}/etc/rc.d/vboxtoolinit
	${INSTALL_DATA} 	${FILESDIR}/machines.conf	${EXAMPLESDIR}/machines.conf
	${INSTALL_DATA} 	${FILESDIR}/vboxtool.conf	${EXAMPLESDIR}/vboxtool.conf
.include <bsd.port.mk>
