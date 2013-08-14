# Created by: Balwinder S "bsd" Dheeman <bsd@rubyforge.org>
# $FreeBSD$

PORTNAME=	ta-lib
PORTVERSION=	0.4.0
CATEGORIES=	devel finance
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	bdheeman@gmail.com
COMMENT=	UNIX, POSIX Library for Technical Analysis

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^LIBTOOL[ ]*=.*|LIBTOOL=${LIBTOOL}|g'

.include <bsd.port.mk>
