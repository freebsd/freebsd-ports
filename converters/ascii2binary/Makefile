PORTNAME=	ascii2binary
PORTVERSION=	2.14
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert between textual representations of numbers and binary
WWW=		https://billposer.org/Software/a2b.html

LICENSE=	GPLv3

USES=		gettext tar:bzip2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ascii2binary bin/binary2ascii \
		share/man/man1/ascii2binary.1.gz \
		share/man/man1/binary2ascii.1.gz

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
