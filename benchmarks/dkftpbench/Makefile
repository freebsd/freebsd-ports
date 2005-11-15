# New ports collection makefile for:	dkftpbench
# Date created:		2004-10-22
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	dkftpbench
PORTVERSION=	0.45
CATEGORIES=	benchmarks ftp
MASTER_SITES=	http://www.kegel.com/dkftpbench/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A FTP benchmark program

PLIST_FILES=	bin/dkftpbench

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_AUTOTOOLS=	automake:14 autoconf:259

.include <bsd.port.mk>
