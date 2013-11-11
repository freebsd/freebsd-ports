# Created by: Holger Lamm <holger@eit.uni-kl.de>
# $FreeBSD$

PORTNAME=	HeroesOfMightAndMagic
PORTVERSION=	3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=
DISTFILES=

MAINTAINER=	mva@FreeBSD.org
COMMENT=	BSD Installation of the Linux game "Heroes of Might and Magic III"

DEPRECATED=	Depends on deprecated Linux GTK1
EXPIRATION_DATE=2013-12-01

PLIST=		${WRKDIR}/PLIST
IS_INTERACTIVE=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	gtk
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	Software is commercial
NO_PACKAGE=	Software is commercial

GAMESUBDIR=	games/Heroes3
GAMEDIR=	${PREFIX}/${GAMESUBDIR}
SCRIPTS_ENV+=	INSTALL_DATA="${INSTALL_DATA}" PLIST=${PLIST} PKGDIR=${PKGDIR}

NO_STAGE=	yes
do-install:
		@cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/do-install

.include <bsd.port.mk>
