PORTNAME=	exams2forms
DISTVERSION=	0.2-0
CATEGORIES=	deskutils education
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Embedding exams exercises in rmarkdown or quarto documents
WWW=		https://cran.r-project.org/package=exams2forms

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-exams>=2.4-2:deskutils/R-cran-exams \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-xfun>0:misc/R-cran-xfun

USES=		cran:auto-plist

.include <bsd.port.mk>
