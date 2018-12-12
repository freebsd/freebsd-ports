# Created by: argv[0] (Iouri V. Ivliev)
# $FreeBSD$

PORTNAME=	panomatic
PORTVERSION=	0.9.4
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ii@any.com.ru
COMMENT=	Tool that automates the creation of control points

BUILD_DEPENDS=	bjam:devel/boost-jam \
		${LOCALBASE}/include/boost/format.hpp:devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include
USES=		dos2unix gmake tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/panomatic

.include <bsd.port.mk>
