# New ports collection makefile for:	dmucs
# Date created:				26 Nov 2007
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dmucs
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Distributed Multi-User Compilation System (for use with distcc)

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_FILES=	bin/dmucs bin/gethost bin/loadavg bin/monitor bin/remhost

.include <bsd.port.mk>
