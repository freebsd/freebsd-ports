# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fastdb
PORTVERSION=	3.75
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Main Memory Relational Database Management System

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

USES=		gmake dos2unix
USE_GCC=	any
MAKE_ENV=	OSTYPE="${OPSYS}"
MAKEFILE=	makefile
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	${MAKEFILE}

PORTDOCS=	FastDB.htm

# The port does not build with C++11 or later (bug 219275).
USE_CXXSTD=	gnu++03

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
