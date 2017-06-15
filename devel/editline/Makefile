# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.15.2
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool ncurses pathfix

PORTDOCS=	*

GH_ACCOUNT=	troglobit
USE_GITHUB=	yes

# Rename to libeditline.3 to avoid conflict with libedit
post-patch:
	@${REINPLACE_CMD} 's|editline.3|lib&|' ${WRKSRC}/man/Makefile.am
	@${MV} ${WRKSRC}/man/editline.3 ${WRKSRC}/man/libeditline.3

.include <bsd.port.mk>
