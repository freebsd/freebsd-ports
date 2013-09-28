# Created by: chinsan
# $FreeBSD$

PORTNAME=	pipestatus
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	UNIX/POSIX shell helper for running pipes safely

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
