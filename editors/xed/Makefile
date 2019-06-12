# Created by: shanee
# $FreeBSD$

PORTNAME=	xed
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	XCONTRIB/editors
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text editor for X

DEPRECATED=	Abandonware using sys/dir.h
EXPIRATION_DATE=	2019-07-12

LICENSE=	MIT

USES=		imake tar:Z
USE_XORG=	xaw
MAKE_ARGS=	BINDIR=${PREFIX}/bin \
		LIBDIR=${PREFIX}/lib/X11 \
		MANPATH=${PREFIX}/man

pre-build:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|extern char \*malloc();|/\* extern char \*malloc(); \*/|g'

.include <bsd.port.mk>
