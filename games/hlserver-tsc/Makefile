# New ports collection makefile for:	TSC Server
# Date created:				Mon Nov 12 13:19:17 BRST 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tsc
PORTVERSION=	0.2.5.2.b
MASTER_SITES=	http://www.fatalgaming.com/ \
		http://207.127.210.8/starsoft/forum/ \
		http://tsc.austin2600.org/ \
		http://www.mystwalker.de/cs/ \
		http://www.wbg-clan.de/download/server/
DISTNAME=	${PORTNAME}${PORTVERSION:S/^0.//:S/.b$/beta/}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS+=	${LINUXBASE}${HLDSDIR}cstrike/liblist.gam:${HALFLIFE_COUNTERSTRIKE_MASTER}

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
PKGDEINSTALL=	${PKGINSTALL}

slaveport-post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
