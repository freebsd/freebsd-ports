
PORTVERSION=	1.43.0
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

CATEGORIES=	devel
MAINTAINER=	churanov.port.maintainer@gmail.com

CONFLICTS+=	boost-python-1* boost-1*
MASTER_SITES=	SF/boost/boost/${PORTVERSION}
