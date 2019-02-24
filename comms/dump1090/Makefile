# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dump1090
PORTVERSION=	20150225
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple Mode S decoder for RTLSDR devices

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	antirez
GH_TAGNAME=	4c53e25

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr

USES=	gmake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lrtlsdr -lusb -lpthread -lm

PLIST_FILES=	bin/dump1090 \
		${DATADIR}/gmap.html

post-patch:
	@${REINPLACE_CMD} -e "s|gmap.html|${DATADIR}/gmap.html|" ${WRKSRC}/dump1090.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gmap.html ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
