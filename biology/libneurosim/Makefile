PORTNAME=	libneurosim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common interfaces for neuronal simulators
WWW=		https://github.com/INCF/libneurosim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	INCF

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_VER:R}
PYTHON_USES=	python

.include <bsd.port.mk>
