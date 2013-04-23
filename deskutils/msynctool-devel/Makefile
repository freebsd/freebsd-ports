# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	msynctool
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line client for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	msynctool-0.2*

USE_BZIP2=	yes
USES=		cmake:outsource pkgconfig

PLIST_FILES=	bin/${PORTNAME}

BROKEN=		fails to build with recent libopensync

post-patch:
# Help find opensync, which is apparently renamed in ports
	${REINPLACE_CMD} -e "s,opensync-1.0,libopensync,g" \
		${WRKSRC}/cmake/modules/FindOpenSync.cmake

.include <bsd.port.mk>
