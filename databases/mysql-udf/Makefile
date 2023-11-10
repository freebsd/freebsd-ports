PORTNAME=	mysql-udf
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of user-defined functions for the MySQL server
WWW=		https://mysql-udf.sourceforge.net/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Upstream last update was in 2007
EXPIRATION_DATE=	2023-12-31

USES=		mysql
IGNORE_WITH_MYSQL=	80

CFLAGS+=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME}

MODULES=	colwidth confidence_higher confidence_lower correlation \
		faculty geomean intercept kurtosis longest median noverm \
		skewness slope stdnorm_density stdnorm_dist weightedavg

.for MODULE in ${MODULES}
PLIST_FILES+=	lib/mysql/plugin/udf_${MODULE}.so
.endfor

do-build:
.for MODULE in ${MODULES}
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -c -o udf_${MODULE}.o udf_${MODULE}.cc && \
	${CC} -shared -o udf_${MODULE}.so udf_${MODULE}.o
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mysql/plugin
.for MODULE in ${MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/udf_${MODULE}.so ${STAGEDIR}${PREFIX}/lib/mysql/plugin/udf_${MODULE}.so
.endfor

.include <bsd.port.mk>
