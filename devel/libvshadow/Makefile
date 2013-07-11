# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvshadow
PORTVERSION=	20130509
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library to support the Volume Service Snapshot (VSS) format

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse pathfix gettext iconv
USE_PYTHON=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		vshadowinfo.1 vshadowmount.1
MAN3=		libvshadow.3

.include <bsd.port.mk>
