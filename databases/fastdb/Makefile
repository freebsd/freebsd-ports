# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fastdb
PORTVERSION=	3.75
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Main Memory Relational Database Management System

LICENSE=	MIT

BROKEN_mips=		fails to compile: unrecognized command line option "-std=gnu++03"
BROKEN_mips64=		fails to compile: unrecognized command line option "-std=gnu++03"
BROKEN_powerpc64=	fails to compile: unrecognized command line option "-std=gnu++03"

USES=		gmake dos2unix
USE_GCC=	any
MAKE_ENV=	OSTYPE="${OPSYS}"
MAKEFILE=	makefile
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	${MAKEFILE}
CXXFLAGS+=	-D_WANT_SEMUN

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FastDB.htm

# The port does not build with C++11 or later (bug 219275).
USE_CXXSTD=	gnu++03

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
