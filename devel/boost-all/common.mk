
PORTVERSION=	1.65.1
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

CONFLICTS+=	boost-python-1* boost-1*
MASTER_SITES=	https://dl.bintray.com/boostorg/release/${PORTVERSION}/source/ \
		SF/boost/boost/${PORTVERSION}

USES+=		tar:bzip2
