# New ports collection makefile for:	Enemy Territory TrueCombat:Elite
# Date created:			25 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enemyterritory-tce
PORTVERSION=	0.48
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://ftp.games.skynet.be/pub/www.filesnetwork.com/Wolfenstein_Enemy_Territory/Mods/Total_Conversions/:full,update \
		http://darkstar.ist.utl.pt/pub/games/:full,update \
		http://ftp.wireplay.co.uk/pub/enemyterritory/mods/tcelite/Linux/:full \
		http://et2.migamer.com/:full \
		http://jogos.bragatel.pt/downloads/et/tcE/linux/:update
PKGNAMEPREFIX=	linux-
DISTNAME=	tcetest
DISTFILES=	tcetest_0209_full.zip:full \
		tcetest_0.48_update.zip:update

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A modern tactical Enemy Territory modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_PACKAGE=	Distfiles are 135MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
ETDIR=		${PREFIX}/lib/enemyterritory

do-build:
.for f in et etded
	@${ECHO} '#!/bin/sh' > ${WRKSRC}/${f}-tce
	@${ECHO} 'exec ${PREFIX}/bin/${f} +set fs_game tcetest "$$@"' >> ${WRKSRC}/${f}-tce
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-tce ${PREFIX}/bin
.endfor

	${MKDIR} ${ETDIR}/tcetest
.for f in cgame.mp.i386.so elitelogoicon.ico maps.cfg mp_bin.pk3 pak0.pk3 \
	pak1.pk3 pak2.pk3 pak3.pk3 qagame.mp.i386.so server.cfg ui.mp.i386.so
	${INSTALL_DATA} ${WRKSRC}/${f} ${ETDIR}/tcetest
.endfor
.for f in cgame.mp.i386.so qagame.mp.i386.so ui.mp.i386.so
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${ETDIR}/tcetest/${f}
	${CHMOD} ${LIBMODE} ${ETDIR}/tcetest/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in README.TXT TCEeula1.0.rtf changelog.txt description.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
