# New ports collection makefile for:   zziplib
# Date created:        3 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	zziplib
PORTVERSION=	0.13.45
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library to provide transparent read access to zipped files

USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-builddir
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
