# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mysql-udf
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of user-defined functions for the MySQL server

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_MYSQL=	yes

MODULES=	colwidth confidence_higher confidence_lower correlation \
		faculty geomean intercept kurtosis longest median noverm \
		skewness slope stdnorm_density stdnorm_dist weightedavg

.for MODULE in ${MODULES}
PLIST_FILES+=	lib/mysql/plugin/udf_${MODULE}.so
.endfor

PLIST_DIRS=	lib/mysql/plugin

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

do-build:
.for MODULE in ${MODULES}
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include/mysql -c -o udf_${MODULE}.o udf_${MODULE}.cc && \
	${CC} -shared -o udf_${MODULE}.so udf_${MODULE}.o
.endfor

do-install:
	${MKDIR} ${PREFIX}/lib/mysql/plugin
.for MODULE in ${MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/udf_${MODULE}.so ${PREFIX}/lib/mysql/plugin/udf_${MODULE}.so
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
