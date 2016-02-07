# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.15.1
CATEGORIES=	devel

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	troglobit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

CONFLICTS_INSTALL=	libedit-*

post-patch:
	${REINPLACE_CMD} -e 's|-ltermcap||' ${WRKSRC}/examples/Makefile.am

.include <bsd.port.mk>
