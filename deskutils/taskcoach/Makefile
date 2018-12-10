# $FreeBSD$

PORTNAME=	taskcoach
DISTVERSION=	1.4.4
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release-${PORTVERSION}
DISTNAME=	TaskCoach-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Friendly task manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	taskcoach.py
USE_PYTHON=	distutils autoplist noflavors
USE_WX=		3.0+
WX_COMPS=	python:lib
NO_ARCH=	yes

PLIST_FILES=	bin/taskcoach \
		share/applications/taskcoach.desktop \
		share/pixmaps/taskcoach.png

post-patch:
	@${REINPLACE_CMD} -e 's|taskcoach.py|taskcoach|' \
		${WRKSRC}/build.in/linux_common/taskcoach.desktop
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/taskcoach.py \
		${STAGEDIR}${PREFIX}/bin/taskcoach
	${INSTALL_DATA} ${WRKSRC}/build.in/linux_common/taskcoach.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icons.in/taskcoach.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
