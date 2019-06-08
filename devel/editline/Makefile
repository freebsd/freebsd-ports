# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.16.1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool ncurses pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

GH_ACCOUNT=	troglobit
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

# Rename to libeditline.3 to avoid conflict with libedit
post-patch:
	@${REINPLACE_CMD} 's|editline.3|lib&|' ${WRKSRC}/man/Makefile.am
	@${MV} ${WRKSRC}/man/editline.3 ${WRKSRC}/man/libeditline.3

.include <bsd.port.mk>
