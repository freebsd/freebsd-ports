PORTNAME=	libantlr3c
DISTVERSION=	3.5
CATEGORIES=	devel
MASTER_SITES=	https://www.antlr3.org/download/
DISTNAME=	antlr-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition (C runtime)
WWW=		https://www.antlr3.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/antlr3-antlr-${DISTVERSION}
WRKSRC_SUBDIR=	runtime/C

.include <bsd.port.mk>
