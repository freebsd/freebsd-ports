# $FreeBSD$

PORTNAME=	courier-unicode
PORTVERSION=	1.1
CATEGORIES=	devel mail
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Courier implementation of Unicode Standard related algorithms

LICENSE=	GPLv3

CONFLICTS=	libunicode-[0-9]*

USES=		iconv libtool perl5 tar:bzip2
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
