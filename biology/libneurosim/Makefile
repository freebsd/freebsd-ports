PORTNAME=	libneurosim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common interfaces for neuronal simulators
WWW=		https://github.com/INCF/libneurosim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	INCF

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	aclocal-1.15=aclocal automake-1.15=automake # workaround for the outdated aclocal-1.15 & automake-1.15 somehow placed into libltdl/Makefile

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_VER:R}
PYTHON_USES=	python

pre-build: # ignore failure of the first run of the build command that always fails first, see https://github.com/INCF/libneurosim/issues/21
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} || ${TRUE}

.include <bsd.port.mk>
