# New ports collection makefile for:	Enemy Territory Fortress
# Date created:			25 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enemyterritory-fortress
PORTVERSION=	1.2
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://camelot.snt.utwente.nl/etf/ \
		ftp://ftp.planet-multiplayer.de/sites/rtcw-prison/et/mods/etf/ \
		http://ftp.games.skynet.be/pub/wolfenstein/etf/
MASTER_SITE_SUBDIR=	distfiles		# for MASTER_SITE_GENTOO
PKGNAMEPREFIX=	linux-
DISTNAME=	etf_${PORTVERSION}-english
EXTRACT_SUFX=	.run

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A class-based teamplay modification for Enemy Territory

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_LINUX=	yes
NO_PACKAGE=	Distfile is 225MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
NO_WRKSUBDIR=	yes
ETDIR=		${PREFIX}/lib/enemyterritory
STRIP=		# do not brand Linux binaries as FreeBSD on INSTALL_PROGRAM

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8763 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -
.for f in etf12.tar.gz cfgnormal.tar.gz
	@cd ${WRKSRC} && ${TAR} zxf ${f}
.endfor

do-build:
	@${ECHO} '#!/bin/sh' > ${WRKSRC}/et-fortress
	@${ECHO} 'exec ${PREFIX}/bin/et +set fs_game etf "$$@"' >> ${WRKSRC}/et-fortress

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/et-fortress ${PREFIX}/bin

	${MKDIR} ${ETDIR}/etf
.for f in autoexec.cfg cgame.mp.i386.so etconfig.cfg etf_pak0.pk3 \
	etf_pak1.pk3 etf_pak2.pk3 mp_bin.pk3 qagame.mp.i386.so \
	sample_server.cfg servercache.dat ui.mp.i386.so
	${INSTALL_DATA} ${WRKSRC}/etf/${f} ${ETDIR}/etf
.endfor
.for f in cgame.mp.i386.so qagame.mp.i386.so ui.mp.i386.so
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${ETDIR}/etf/${f}
	${CHMOD} ${LIBMODE} ${ETDIR}/etf/${f}
.endfor

.for d in classconfigs ui/usermenu video
	${MKDIR} ${ETDIR}/etf/${d}
	${INSTALL_DATA} ${WRKSRC}/etf/${d}/* ${ETDIR}/etf/${d}
.endfor

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etf.xpm ${DATADIR}

.for d in advanced_server_configs sample_server
	${MKDIR} ${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/etf/${d:S/_/\ /g}/* ${DATADIR}/${d}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in EULA README etf/12_changelog.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
