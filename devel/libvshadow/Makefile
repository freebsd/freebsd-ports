# New ports collection makefile for:	libvshadow
# Date created:		31 May 2012
# Whom:			MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libvshadow
PORTVERSION=	20130113
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library to support the Volume Service Snapshot (VSS) format

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_FUSE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack
USE_ICONV=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		vshadowinfo.1 vshadowmount.1
MAN3=		libvshadow.3

.include <bsd.port.mk>
