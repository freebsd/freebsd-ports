# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	v1541commander
PORTVERSION=	1.1
CATEGORIES=	archivers emulators

MAINTAINER=	felix@palmen-it.de
COMMENT=	Virtual 1541 disk commander

LICENSE=	BSD2CLAUSE STYLEFONT
LICENSE_COMB=	multi
LICENSE_NAME_STYLEFONT=		The STYLE C64 TrueType Fonts License
LICENSE_FILE_STYLEFONT=		${WRKSRC}/LICENSE-font.txt
LICENSE_PERMS_STYLEFONT=	dist-mirror no-dist-sell pkg-mirror \
				no-pkg-sell auto-accept

LIB_DEPENDS=	lib1541img.so:archivers/lib1541img

USES=		compiler:c++11-lang gmake pkgconfig qt:5 shared-mime-info

USE_QT=		core gui network widgets buildtools_build linguisttools_build

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME} zimk:zimk
GH_ACCOUNT=	excess-c64 Zirias:zimk
GH_TAGNAME=	v${PORTVERSION} 31500ca:zimk

OPTIONS_DEFINE=	DOCS

MAKE_ARGS=	pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		V=1
ALL_TARGET=	strip

post-extract:
	@${MV} ${WRKDIR}/zimk-*/* ${WRKSRC}/zimk/

.include <bsd.port.mk>
