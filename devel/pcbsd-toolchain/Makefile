# New ports collection makefile for:	pcbsd-toolchain
# $FreeBSD$

PORTNAME=	pcbsd-toolchain
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=
DISTFILES=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Development Utilities

RUN_DEPENDS=	moc-qt4:${PORTSDIR}/devel/qt4-moc \
		uic-qt4:${PORTSDIR}/devel/qt4-uic \
		linguist-qt4:${PORTSDIR}/devel/qt4-linguist \
		designer-qt4:${PORTSDIR}/devel/qt4-designer \
		qmake-qt4:${PORTSDIR}/devel/qmake4

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
