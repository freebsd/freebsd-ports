# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=	fowsr
PORTVERSION=	${FILEVER}
CATEGORIES=	astro
DISTNAME=	fowsr-${FILEVER}
USE_GITHUB=	yes
GH_ACCOUNT=	apachler
GH_PROJECT=	fowsr
GH_TAGNAME= 571db38
MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fine Offset Weather Station Reader

LICENSE=	GPLv3

FILEVER=	2.0
WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}/${PORTNAME}.src

USES=		gmake dos2unix

PLIST_FILES=	bin/fowsr

post-patch:
	${REINPLACE_CMD} 's:gcc:${CC}:g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} 's:/usr/bin/fowsr:fowsr:g ; s://var//://var/tmp//:g' \
	    ${WRKSRC}/*.sh ${WRKSRC}/fowsr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fowsr ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
