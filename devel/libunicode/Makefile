PORTNAME=	libunicode
PORTVERSION=	0.4
PORTREVISION=	13
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/libunicode
DISTNAME=	${PORTNAME}-${PORTVERSION}.gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for manipulating Unicode characters and strings
WWW=		https://www.gnome.org/

USES=		iconv libtool

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
