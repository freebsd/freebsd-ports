# New ports collection makefile for:	ucl
# Date created:				29 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ucl
PORTVERSION=	1.02
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A data compression library with low memory usage during decompression

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	COPYING README

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/uclpack \
		${PREFIX}/bin/uclpack
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA}	${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
