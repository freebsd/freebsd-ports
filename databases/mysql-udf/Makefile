# New ports collection makefile for:	mysql-udf
# Date created:		April 2008
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-udf
PORTVERSION=	0.3
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Set of user-defined functions for the MySQL server

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_MYSQL=	yes
IGNORE_WITH_MYSQL_VER=	323

MODULES=	colwidth confidence_higher confidence_lower correlation \
		faculty geomean intercept kurtosis longest median noverm \
		skewness slope stdnorm_density stdnorm_dist weightedavg

.for MODULE in ${MODULES}
PLIST_FILES+=	lib/mysql/udf_${MODULE}.so
.endfor

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
.for MODULE in ${MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/udf_${MODULE}.so ${PREFIX}/lib/mysql/udf_${MODULE}.so
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
