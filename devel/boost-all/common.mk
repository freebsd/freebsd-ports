
PORTVERSION=	1.55.0
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

CONFLICTS+=	boost-python-1* boost-1*
MASTER_SITES=	SF/boost/boost/${PORTVERSION}

USES+=		cpe tar:bzip2
CPE_VENDOR=	boost
CPE_PRODUCT=	boost
