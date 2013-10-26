# Created by: laddassm
# $FreeBSD$

PORTNAME=	klat4
PORTVERSION=	0.6.1
PORTREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	http://klat.algebraic.ru/

MAINTAINER=	laddassm@gmail.com
COMMENT=	A LaTeX source editor for KDE4

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/katepart.so:${PORTSDIR}/editors/kate

USE_BZIP2=	yes
USES=		cmake
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build

NO_STAGE=	yes
.include <bsd.port.mk>
