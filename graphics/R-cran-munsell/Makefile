PORTNAME=	munsell
PORTVERSION=	0.5.1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Munsell colour system
WWW=		https://cran.r-project.org/web/packages/munsell/

LICENSE=	CW MIT
LICENSE_COMB=	multi
LICENSE_NAME_CW=	Charlotte Wickham COPYRIGHT
LICENSE_FILE_CW=	${WRKSRC}/LICENSE
LICENSE_PERMS_CW=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	R-cran-colorspace>0:graphics/R-cran-colorspace

USES=		cran:auto-plist

.include <bsd.port.mk>
