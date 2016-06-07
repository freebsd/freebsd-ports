# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.15.2
CATEGORIES=	devel

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	troglobit

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} 's|-ltermcap||' ${WRKSRC}/examples/Makefile.am
	${REINPLACE_CMD} '/^pkgconfigdir/s|=.*|= ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am
	# rename to libeditline.3 to avoid conflict with libedit
	${REINPLACE_CMD} 's|editline.3|lib&|' ${WRKSRC}/man/Makefile.am
	cd ${WRKSRC}/man; ${MV} editline.3 libeditline.3

.include <bsd.port.mk>
