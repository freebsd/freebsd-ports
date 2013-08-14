# $FreeBSD$

PORTNAME=	liblognorm
PORTVERSION=	0.3.5
CATEGORIES=	devel net security
MASTER_SITES=	http://www.liblognorm.com/download/files/download/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A log normalizer

LICENSE=	GPLv2

LIB_DEPENDS=	ee:${PORTSDIR}/devel/libee \
		estr:${PORTSDIR}/devel/libestr

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
