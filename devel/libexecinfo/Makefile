# New ports collection makefile for:	libexecinfo
# Date created:				10 August 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libexecinfo
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.portaone.com/~sobomax/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for inspecting program's backtrace

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
MAKE_FLAGS=	LIBDIR=${PREFIX}/lib \
		INCLUDEDIR=${PREFIX}/include

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
