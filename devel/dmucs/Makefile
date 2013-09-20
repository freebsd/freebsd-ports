# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmucs
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Distributed Multi-User Compilation System (for use with distcc)

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dmucs bin/gethost bin/loadavg bin/monitor bin/remhost

NO_STAGE=	yes
.include <bsd.port.mk>
