# Created by: pjm
# $FreeBSD$

PORTNAME=	vboxtool
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides effective control of VirtualBox machines

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	VBoxManage:emulators/virtualbox-ose\
		bash:shells/bash

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		zip
GROUPS=		vboxusers

SAMPLESDIR=	${PREFIX}/share/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|!/bin/bash|!/usr/bin/env bash|' \
		-e 's|/etc/|${PREFIX}&|g' \
		${WRKSRC}/script/vboxtool \
		${WRKSRC}/script/vboxtoolinit

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/vboxtool.conf ${STAGEDIR}${ETCDIR}/vboxtool.conf.sample
	${INSTALL_DATA} ${FILESDIR}/machines.conf ${STAGEDIR}${ETCDIR}/machines.conf.sample
	${INSTALL_SCRIPT} -m 0750 ${WRKSRC}/script/vboxtool ${STAGEDIR}${PREFIX}/bin/vboxtool
	${INSTALL_SCRIPT} -m 0750 ${WRKSRC}/script/vboxtoolinit ${STAGEDIR}${PREFIX}/etc/rc.d/vboxtoolinit

.include <bsd.port.mk>
