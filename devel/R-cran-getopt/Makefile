PORTNAME=	getopt
DISTVERSION=	1.20.3
PORTREVISION=	2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Accept short and long flags in Rscript
WWW=		https://cran.r-project.org/web/packages/getopt/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cran:auto-plist

post-patch:
	@${REINPLACE_CMD} -i '' -e \
		's|/path/to/Rscript|${LOCALBASE}/bin/Rscript|' \
		${WRKSRC}/exec/example.R

.include <bsd.port.mk>
