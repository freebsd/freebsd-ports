# New ports collection makefile for:	ksteak
# Date created:		2003/02/16
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ksteak
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	german kde
MASTER_SITES=	http://www.der-fritz.de/ksteak/

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	KDE frontend for steak, an english - german dictionary

RUN_DEPENDS=	steak:${PORTSDIR}/german/steak

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ksteak/ksteakui.rc ${PREFIX}/share/apps/ksteak

.include <bsd.port.mk>
