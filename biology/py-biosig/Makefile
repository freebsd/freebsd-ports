PORTNAME=	biosig
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/BioSig%20for%20C_C%2B%2B/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for reading and writing different biosignal data format
WWW=		http://biosig.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../../COPYING

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libbiosig.so:biology/biosig

USES=		python tar:xz
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	biosig4c++/python

.include <bsd.port.mk>
