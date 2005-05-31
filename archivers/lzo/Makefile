# New ports collection makefile for:	lzo
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	lzo
PORTVERSION=	2.00
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable speedy, lossless data compression library

USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
