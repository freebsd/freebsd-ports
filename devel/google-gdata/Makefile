# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gdata
PORTVERSION=	2.2.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DOT NET library for the Google Data API

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Newtonsoft.Json.pc:devel/newtonsoft-json

USE_GITHUB=	yes
GH_TUPLE=	google:google-gdata:edcd096379

USES=		dos2unix gmake mono pathfix
PATHFIX_MAKEFILEIN=	Makefile
WRKSRC_SUBDIR=	clients/cs
DOS2UNIX_FILES=	${WRKSRC}/Makefile ${WRKSRC}/misc/gdata-sharp-core.pc.in
MAKE_ARGS=	CSC=${LOCALBASE}/bin/mcs
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile

post-install:
	cd ${STAGEDIR}${PREFIX}; ${FIND} lib/mono libdata/pkgconfig \
		\( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
