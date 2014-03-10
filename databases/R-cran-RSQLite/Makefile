# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RSQLite
PORTVERSION=	0.11.2
PORTREVISION=	6
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Database Interface R driver for SQLite

LICENSE=	LGPL20

BUILD_DEPENDS=	R-cran-DBI>=0.2.5:${PORTSDIR}/databases/R-cran-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
