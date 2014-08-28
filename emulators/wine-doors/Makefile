# Created by: ports@mcdermottroe.com
# $FreeBSD$

PORTNAME=	wine-doors
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	src-
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME:S/-//}/archive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows application management for the GNOME Desktop

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		orange:${PORTSDIR}/archivers/liborange \
		unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cairo>0:${PORTSDIR}/graphics/py-cairo \
		bash:${PORTSDIR}/shells/bash

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		python:run shebangfix
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
SHEBANG_FILES=	src/winedoors.py
USE_GNOME=	pygnomedesktop:run

SUB_FILES=	preferences.xml

.include <bsd.port.options.mk>

.if ${ARCH} == i386
RUN_DEPENDS+=	wine>0:${PORTSDIR}/emulators/wine
.else
RUN_DEPENDS+=	i386-wine>0:${PORTSDIR}/emulators/i386-wine
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|"/etc/wine-doors|"${ETCDIR}|' ${WRKSRC}/src/preferences.py
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash|'

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKDIR} && ${INSTALL_DATA} preferences.xml \
		${STAGEDIR}${ETCDIR})
	(cd ${WRKSRC}/dist && ${INSTALL_DATA} wine-doors.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in dtd pixmaps registry src
	@${TAR} -C ${WRKSRC} --exclude "*.bak" -cf - ${i} | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -
.endfor
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${DATADIR} -f ${DATADIR_REL})
	@${LN} -sf ${DATADIR}/src/winedoors.py \
		${STAGEDIR}${PREFIX}/bin/wine-doors
	@${LN} -sf ${DATADIR}/pixmaps/wine-doors.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/wine-doors.png
	@${LN} -sf ${DATADIR}/pixmaps/wine-doors.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/wine-doors.svg

.include <bsd.port.mk>
