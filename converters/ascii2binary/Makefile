# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ascii2binary
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert between textual representations of numbers and binary

LICENSE=	GPLv3

USES=		gettext tar:bzip2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ascii2binary bin/binary2ascii \
		man/man1/ascii2binary.1.gz \
		man/man1/binary2ascii.1.gz

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
