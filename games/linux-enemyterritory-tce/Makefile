# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enemyterritory-tce
PORTVERSION=	0.49
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://dragons-perch.net/tce/
PKGNAMEPREFIX=	linux-
DISTNAME=	tcetest
DISTFILES=	tcetest049.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern tactical Enemy Territory modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386 amd64
USE_ZIP=	yes
USE_LINUX=	yes
NO_PACKAGE=	Distfile size is 450MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
ETDIR=		${PREFIX}/lib/enemyterritory
PORTDOCS=	*

DESKTOP_ENTRIES="Enemy Territory TrueCombat:Elite" \
		"Play Enemy Territory TrueCombat:Elite" \
		"${ETDIR}/tcetest/tce_icon_pc.ico" \
		"et-tce" \
		"" \
		false

do-build:
.for f in et etded
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/${f}-tce
	@${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game tcetest "$$@"' >> ${WRKSRC}/${f}-tce
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-tce ${PREFIX}/bin
.endfor

	${MKDIR} ${ETDIR}/tcetest
.for f in autoexec.cfg cgame.mp.i386.so mp_bin.pk3 official.dat pak0.pk3 \
	pak1.pk3 pak2.pk3 pak3.pk3 qagame.mp.i386.so tce_icon_pc.ico \
	ui.mp.i386.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${ETDIR}/tcetest
.endfor
.for f in cgame.mp.i386.so qagame.mp.i386.so ui.mp.i386.so
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${ETDIR}/tcetest/${f}
	${CHMOD} ${LIBMODE} ${ETDIR}/tcetest/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in *.txt *.rtf
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
