# Created by: Joachim Strombergson <watchman@ludd.ltu.se>
# $FreeBSD$

PORTNAME=	shftool
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://www.df.lth.se/~triad/krad/shftool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converter for the Standard Hex Format (SHF)

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,^LIBLOC_LIST=.*,LIBLOC_LIST=${LOCALBASE},' \
		${WRKSRC}/configure

.include <bsd.port.mk>
