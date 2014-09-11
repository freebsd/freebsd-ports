# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	BitcoinArmory
PORTVERSION=	0.92.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	https://codeload.github.com/etotheipi/BitcoinArmory/tar.gz/v${PORTVERSION}?dummy=/

MAINTAINER=	yuri@rawbw.com
COMMENT=	An implementation of desktop bitcoin management system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/swig3.0:${PORTSDIR}/devel/swig30 \
		${LOCALBASE}/bin/pyrcc4:${PORTSDIR}/textproc/py-qt4-xml \
		${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}twistedCore>=14.0.0:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}psutil>1.2.1:${PORTSDIR}/sysutils/py-psutil

USES=		gmake python
USE_GCC=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	PYTHON_CONFIG=${PYTHON_CMD}-config

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	low-level code available only for i386 and amd64

post-patch:
	@${REINPLACE_CMD} 's/python-config/$${PYTHON_CONFIG}/' ${WRKSRC}/cppForSwig/Makefile
post-stage:
	@${SED} -i.bak -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${STAGEDIR}/${LOCALBASE}/bin/armory && \
		${RM} -f ${STAGEDIR}/${LOCALBASE}/bin/armory.bak
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/armory/_CppBlockUtils.so

.include <bsd.port.mk>
