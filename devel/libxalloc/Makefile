# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	libxalloc
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	xalloc-${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	A memory allocation library with error checking

MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
