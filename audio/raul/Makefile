# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raul
PORTVERSION=	0.8.0
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ utility library primarily aimed at audio/musical applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-03-19

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES=		gnome pkgconfig python:2.7,build tar:bzip2 waf
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libraul.so

post-patch:
	@${REINPLACE_CMD} -e \
		"s|$$[{]LIBDIRNAME[}]/pkgconfig|libdata/pkgconfig| ; \
		 s|-fshow-column'|-fshow-column ${CXXFLAGS}'|" \
			${WRKSRC}/autowaf/autowaf.py

.include <bsd.port.mk>
