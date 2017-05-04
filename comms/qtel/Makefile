# Created by: shurd
# $FreeBSD$

PORTNAME=	qtel
PORTREVISION=	1

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Qtel Echolink client

LICENSE=	GPLv2

LIB_DEPENDS=	libecholib.so:comms/svxlink

MASTERDIR=	${.CURDIR}/../svxlink
USE_QT4=	corelib gui network qmake_build linguist_build moc_build rcc_build uic_build
PKGDIR=		${.CURDIR}
CMAKE_ARGS+=	-DUSE_QT:BOOL=YES \
		-DQT_ONLY:BOOL=YES

.include "${MASTERDIR}/Makefile"
