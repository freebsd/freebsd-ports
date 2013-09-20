# Created by: Thomas Hentschel <thomas at hentschel dot net>
# $FreeBSD$

PORTNAME=	orbitcpp
PORTVERSION=	1.3.9
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ bindings for ORBit, a CORBA 2.2-compliant ORB

USE_BZIP2=	yes
USE_GNOME=	gnomehack ltverhack orbit2
USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS =.*\)test\(.*\)|\1\2|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
