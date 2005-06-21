# New ports collection makefile for:	TSC Server
# Date created:				Mon Nov 12 13:19:17 BRST 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tsc
PORTVERSION=	0.2.5.3.b
PORTREVISION=	1
MASTER_SITES=	http://tsc.austin2600.org/ \
		http://www.mystwalker.de/cs/
DISTNAME=	${PORTNAME}${PORTVERSION:S/^0.//:S/.b$/beta/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Counter-Strike with TSC modifications

BUILD_DEPENDS+=	${LINUXBASE}${HLDSDIR}cstrike/liblist.gam:${HALFLIFE_COUNTERSTRIKE_MASTER}

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PKGDEINSTALL=	${PKGINSTALL}

slaveport-post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
