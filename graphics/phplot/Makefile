# New ports collection makefile for:	phplot
# Date created:         21 Oct 2001
# Whom:                 yukinopo@livedoor.com
#
# $FreeBSD$

PORTNAME=	phplot
PORTVERSION=	4.4.6
PORTREVISION=	2
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phplot
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yukinopo@livedoor.com
COMMENT=	A PHP class for creating scientific and business charts

USE_PHP=	yes
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}
PHPLOT_DIR=	lib/php/phplot

PHPLOT_EXAMPLE=	share/phplot

LIBS=		phplot.php phplot_data.php rgb.inc.php benjamingothic.ttf

DOCS=		internal_functions.html function_reference.html \
		index.html examples.html quick_start.php \
		user_functions.html user_internal_functions.html

EXAMPLES=	0cars.jpg benjamingothic.ttf create_chart.php \
		data.php data_date.php data_date2.php data_sample1.php data_sample2.php \
		data_sample3.php data_sample4.php example1.php example10.php \
		example11.php example12.php example13.php example2.php \
		example3.php example4.php example5.php example6.php \
		example7.php example8.php example9.php format_chart.php \
		inline_image.php rgb.inc.php test1.php test_setup.php

do-install:
	@${MKDIR} ${PREFIX}/${PHPLOT_DIR} 2>/dev/null||true
.for FILE in ${SAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} \
       	@${PREFIX}/${PHPLOT_DIR}/${FILE}
.endfor

.for FILE in ${LIBS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${PHPLOT_DIR}
.endfor
	@${MKDIR} ${PREFIX}/${PHPLOT_EXAMPLE}
	@${MKDIR} ${PREFIX}/${PHPLOT_EXAMPLE}/doc
	@${MKDIR} ${PREFIX}/${PHPLOT_EXAMPLE}/examples
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${PREFIX}/${PHPLOT_EXAMPLE}/doc
.endfor

.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${FILE} ${PREFIX}/${PHPLOT_EXAMPLE}/examples
.endfor

.include <bsd.port.mk>
