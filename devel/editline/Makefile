# $FreeBSD$

PORTNAME=	editline
PORTVERSION=	1.17.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/troglobit/editline/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minix editline: A free readline() for UNIX

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool ncurses pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
# Rename editline.3 to libeditline.3 to avoid conflict with libedit
	@${MV} ${WRKSRC}/man/editline.3 ${WRKSRC}/man/libeditline.3

.include <bsd.port.mk>
