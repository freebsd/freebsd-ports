# New ports collection makefile for:	Enemy Territory Fortress
# Date created:			25 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enemyterritory-fortress
PORTVERSION=	1.4
PORTREVISON=	1
CATEGORIES=	games linux
MASTER_SITES=	http://ftp.games.skynet.be/pub/wolfenstein/etf/ \
		http://www.playlinux.net/pub/files/native/
PKGNAMEPREFIX=	linux-
DISTNAME=	etf_${PORTVERSION}-english-2
EXTRACT_SUFX=	.run

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A class-based teamplay modification for Enemy Territory

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_PACKAGE=	Distfile is 249MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
NO_WRKSUBDIR=	yes
ETDIR=		${PREFIX}/lib/enemyterritory

do-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && \
		${TAIL} -c +8497 ${DISTDIR}/${DISTFILES} | ${TAR} zxf - && \
		${TAR} zxf etf.tar.gz && \
		${TAR} zxf cfgnormal.tar.gz)

do-build:
.for f in et etded
	@${ECHO} '#!/bin/sh' > ${WRKSRC}/${f}-fortress
	@${ECHO} 'exec ${PREFIX}/bin/${f} +set fs_game etf "$$@"' >> ${WRKSRC}/${f}-fortress
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-fortress ${PREFIX}/bin
.endfor

	${MKDIR} ${ETDIR}/etf
.for f in autoexec.cfg etconfig.cfg etf_dissect.pk3 etf_pak0.pk3 \
	etf_pak1.pk3 etf_pak2.pk3 etf_pak3.pk3 etf_server.cfg \
	mp_bin.pk3 preset_normal.cfg servercache.dat
	${INSTALL_DATA} ${WRKSRC}/etf/${f} ${ETDIR}/etf
.endfor
.for f in cgame.mp.i386.so omnibot_etf.so qagame.mp.i386.so ui.mp.i386.so
	${INSTALL} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} ${WRKSRC}/etf/${f} \
		${ETDIR}/etf
.endfor

.for d in classconfigs nav scripts ui/usermenu video
	${MKDIR} ${ETDIR}/etf/${d}
	${INSTALL_DATA} ${WRKSRC}/etf/${d}/* ${ETDIR}/etf/${d}
.endfor

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etf.xpm ${DATADIR}

	${MKDIR} ${EXAMPLESDIR}/sample_server
.for f in sample_server.cfg sample_srv/*
	${INSTALL_DATA} ${WRKSRC}/etf/${f} ${EXAMPLESDIR}/sample_server
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in LICENSE README etf/ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
