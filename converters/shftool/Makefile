# Created by: Joachim Strombergson <watchman@ludd.ltu.se>
# $FreeBSD$

PORTNAME=	shftool
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	http://www.df.lth.se/~triad/krad/shftool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converter for the Standard Hex Format (SHF)

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

post-patch:
	${REINPLACE_CMD} -e 's,^LIBLOC_LIST=.*,LIBLOC_LIST=${LOCALBASE},' \
		${WRKSRC}/configure

.include <bsd.port.mk>
