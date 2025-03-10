PORTNAME=	libedit
DISTVERSION=	3.1-20240808
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://thrysoee.dk/editline/
DISTNAME=	${PORTNAME}-${PORTVERSION:E}-${PORTVERSION:R}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line editor library
WWW=		https://thrysoee.dk/editline/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool localbase ncurses pathfix
CPE_VENDOR=	libedit_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
