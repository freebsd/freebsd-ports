# New ports collection makefile for: gdbm
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	1.8.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN3=		gdbm.3

INSTALL_INFO?=	install-info

post-install:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
