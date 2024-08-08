PORTNAME=	exams
DISTVERSION=	2.4-1
CATEGORIES=	deskutils education
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Automatic generation of exams in R
WWW=		https://cran.r-project.org/web/packages/exams/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-openxlsx>0:textproc/R-cran-openxlsx \
		R-cran-png>0:graphics/R-cran-png \
		R-cran-RCurl>0:ftp/R-cran-RCurl \
		R-cran-RJSONIO>0:converters/R-cran-RJSONIO \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-tinytex>0:print/R-cran-tinytex \
		R-cran-tth>0:textproc/R-cran-tth \
		R-cran-xml2>0:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS} \
		hs-pandoc>0:textproc/hs-pandoc

USES=		cran:auto-plist

.include <bsd.port.mk>
