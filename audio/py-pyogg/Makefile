PORTNAME=	PyOgg
DISTVERSION=	0.6.14a1
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Xiph.org's Ogg Vorbis, Opus, and FLAC for Python
WWW=		https://pypi.org/project/PyOgg/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/lib/libFLAC.so:audio/flac \
		${LOCALBASE}/lib/libogg.so:audio/libogg \
		${LOCALBASE}/lib/libopusfile.so:audio/opusfile \
		${LOCALBASE}/lib/libvorbis.so:audio/libvorbis

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# Prevent needless (and wrong) PATH poisoning on Unix-like systems
post-patch:
	@${REINPLACE_CMD} -e '48,/os\.environ\["PATH"\]/d' \
		${WRKSRC}/pyogg/library_loader.py

.include <bsd.port.mk>
