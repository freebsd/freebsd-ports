# Created by: Martin Matuska <mm@FreeBSD.org>

PORTNAME=	mysql-udf
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of user-defined functions for the MySQL server

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		mysql
CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc=	-fPIC
CFLAGS_powerpc64=	-fPIC
CFLAGS_powerpc64le=	-fPIC

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
