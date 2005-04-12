# New ports collection makefile for:	ucl
# Date created:				29 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ucl
PORTVERSION=	1.03
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A data compression library with low memory usage

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	AUTHORS NEWS README THANKS TODO

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/uclpack ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA}	${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
