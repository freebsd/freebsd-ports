PORTNAME=	exams
DISTVERSION=	2.4-3
CATEGORIES=	deskutils education
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Automatic generation of exams in R
WWW=		https://cran.r-project.org/web/packages/exams/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

RUN_DEPENDS=	hs-pandoc>0:textproc/hs-pandoc \
		R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-openxlsx>0:textproc/R-cran-openxlsx \
		R-cran-png>0:graphics/R-cran-png \
		R-cran-RCurl>0:ftp/R-cran-RCurl \
		R-cran-RJSONIO>0:converters/R-cran-RJSONIO \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-tinytex>0:print/R-cran-tinytex \
		R-cran-tth>0:textproc/R-cran-tth \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		zip>0:archivers/zip
TEST_DEPENDS=	pdftex:print/tex-formats \
		R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-qpdf>0:graphics/R-cran-qpdf \
		tex-dvipsk>0:print/tex-dvipsk

USES=		cran:auto-plist

MAKE_ENV=	LC_ALL=C.UTF-8 \
		R_ZIPCMD=${LOCALBASE}/bin/zip

.include <bsd.port.mk>
