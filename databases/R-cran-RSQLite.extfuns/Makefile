# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>

PORTNAME=	RSQLite.extfuns
PORTVERSION=	0.0.1
PORTREVISION=	13
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	SQLite extension functions for RSQLite

LICENSE=	APACHE20

DEPRECATED=	RSQLite incorporates RSQLite.extfuns
EXPIRATION_DATE=	2022-05-31

CONFLICTS=	R-cran-RSQLite

BUILD_DEPENDS=	R-cran-RSQLite>=0.11.1<1.0.0:databases/R-cran-RSQLite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
