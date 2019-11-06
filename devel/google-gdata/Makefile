# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gdata
PORTVERSION=	2.2.0.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DOT NET library for the Google Data API

BROKEN=		unfetchable

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/Newtonsoft.Json.pc:devel/newtonsoft-json
NUGET_DEPENDS=	nunit.framework=2.63.0

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	edcd096379

USES=		dos2unix gmake mono:nuget pathfix
NUGET_LAYOUT=	flat
PATHFIX_MAKEFILEIN=	Makefile
WRKSRC_SUBDIR=	clients/cs
DOS2UNIX_FILES=	${WRKSRC}/Makefile ${WRKSRC}/misc/gdata-sharp-core.pc.in
MAKE_ARGS=	CSC=${LOCALBASE}/bin/csc SN=${LOCALBASE}/bin/sn
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -Ee 's|(-keyfile:(.*))|\1 -delaysign+\'$$'\n'$$'\t''$$(SN) -R $$@ \2|g' ${WRKSRC}/Makefile

post-install:
	cd ${STAGEDIR}${PREFIX}; ${FIND} lib/mono libdata/pkgconfig \
		\( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
