# $FreeBSD$

PORTNAME=	csmith
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Generates random C programs that conform to the C99 standard

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
