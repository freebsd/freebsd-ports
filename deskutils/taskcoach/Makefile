# $FreeBSD$

PORTNAME=	taskcoach
PORTVERSION=	1.3.31
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release-${PORTVERSION}
DISTNAME=	TaskCoach-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Friendly task manager

WRKSRC=		${WRKDIR}/${DISTNAME}

LICENSE=	GPLv3
LICENSE_FILE=   ${WRKSRC}/LICENSE.txt
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_EGGINFO=${DISTNAME}-py${PYTHON_VER}.egg-info
USE_WX=		2.8
WX_COMPS=	python:lib
WX_UNICODE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|taskcoach.py|taskcoach|' \
		${WRKSRC}/build.in/fedora/taskcoach.desktop
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/taskcoach.py ${PREFIX}/bin/taskcoach
	@${INSTALL_DATA} ${WRKSRC}/build.in/fedora/taskcoach.desktop \
		${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/icons.in/taskcoach.png \
		${PREFIX}/share/pixmaps

.include <bsd.port.mk>
