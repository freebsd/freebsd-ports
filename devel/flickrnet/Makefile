# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	flickrnet
PORTVERSION=	2.2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://romain.blogreen.org/distfiles/
DISTNAME=	FlickrNet${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}-Src-48055

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flickr .Net API Library

LICENSE=	CPL-1.0 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_NAME_CPL-1.0=	Common Public License 1.0
LICENSE_PERMS_CPL-1.0=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		dos2unix mono zip
DOS2UNIX_GLOB=	*.cs
WRKSRC=		${WRKDIR}/FlickrNet

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mcs -t:library -out:FlickrNet.dll -r:System.Data -r:System.Web -r:System.Drawing *.cs

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mono/flickrnet
	cd ${WRKSRC} && ${INSTALL_DATA} FlickrNet.dll ${STAGEDIR}${PREFIX}/lib/mono/flickrnet
	cd ${WRKSRC} && ${SED} -e 's|@prefix@|${PREFIX}|' < flickrnet.pc.in > flickrnet.pc
	cd ${WRKSRC} && ${INSTALL_DATA} flickrnet.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
