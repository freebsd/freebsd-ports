# ex:ts=8
# Ports collection makefile for:	dbh
# Date created:			Aug 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbh
PORTVERSION=	1.0.14
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Disk Based Hashtables

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|libdir[)]/pkgconfig|prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
