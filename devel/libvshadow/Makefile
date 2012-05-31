# New ports collection makefile for:	libvshadow
# Date created:		31 May 2012
# Whom:			MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libvshadow
PORTVERSION=	20120511
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-experimental-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library to support the Volume Service Snapshot (VSS) format

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	fuse:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		vshadowinfo.1
MAN3=		libvshadow.3

.include <bsd.port.mk>
