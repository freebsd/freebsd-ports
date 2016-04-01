# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gdata
PORTVERSION=	2.2.0.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	libgoogle-data-mono-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DOT NET library for the Google Data API

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Newtonsoft.Json.pc:devel/newtonsoft-json

USES=		dos2unix gmake mono
DOS2UNIX_FILES=	Makefile misc/gdata-sharp-core.pc.in
MAKE_ARGS=	CSC=${LOCALBASE}/bin/mcs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile

post-stage:
	cd ${STAGEDIR}${PREFIX}; ${FIND} lib/mono libdata/pkgconfig \
		\( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
