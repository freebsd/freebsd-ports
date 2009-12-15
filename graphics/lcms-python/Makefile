# New ports collection makefile for:	lcms-python
# Date created:		13/10/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.19
CATEGORIES=	graphics devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.19 \
		http://www.littlecms.com/
PKGNAMESUFFIX=	-python

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Light Color Management System (python bindings)

LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/lcms-1.19
PLIST_FILES=	${PYTHON_SITELIBDIR:C,${PREFIX}/?,,}/_lcms.so \
		${PYTHON_SITELIBDIR:C,${PREFIX}/?,,}/lcms.py

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}/python && ${SETENV} ${MAKE_ENV} ${MAKE} all

do-install:
	${INSTALL_DATA} ${WRKSRC}/python/.libs/_lcms.so \
		${PYTHON_SITELIBDIR}/_lcms.so
	${INSTALL_DATA} ${WRKSRC}/python/lcms.py \
		${PYTHON_SITELIBDIR}/lcms.py

.include <bsd.port.post.mk>
