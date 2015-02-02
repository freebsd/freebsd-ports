# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.14.2
CATEGORIES=	devel
MASTER_SITES=	GHR

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE

USES=		libtool
USE_GITHUB=	yes
GH_ACCOUNT=	troglobit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	libedit-*

.include <bsd.port.mk>
