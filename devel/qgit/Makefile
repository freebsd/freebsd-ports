# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qgit
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Graphical interface to git repositories

BROKEN=		unfetchable

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		core gui widgets \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	tibirna

.include <bsd.port.mk>
