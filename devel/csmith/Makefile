# $FreeBSD$

PORTNAME=	csmith
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Generates random C programs that conform to the C99 standard

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.mk>
