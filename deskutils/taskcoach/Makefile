# $FreeBSD$

PORTNAME=	taskcoach
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release-${PORTVERSION}
DISTNAME=	TaskCoach-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Friendly task manager

WRKSRC=		${WRKDIR}/${DISTNAME}

LICENSE=	GPLv3
LICENSE_FILE=   ${WRKSRC}/LICENSE.txt
USES=		python twisted
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=${DISTNAME}-py${PYTHON_VER}.egg-info
USE_WX=		3.0+
WX_COMPS=	python:lib
WX_UNICODE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|taskcoach.py|taskcoach|' \
		${WRKSRC}/build.in/linux_common/taskcoach.desktop
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/taskcoach.py \
		${STAGEDIR}${PREFIX}/bin/taskcoach
	@${INSTALL_DATA} ${WRKSRC}/build.in/linux_common/taskcoach.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons.in/taskcoach.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
