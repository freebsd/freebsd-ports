# Created by: shurd
# $FreeBSD$

PORTNAME=	qtel

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Qtel Echolink client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libecholib.so:comms/svxlink \
		libgsm.so:audio/gsm

MASTERDIR=	${.CURDIR}/../svxlink
USES=		qt:5 gnome
USE_QT=		buildtools core gui linguisttools network qmake widgets
USE_GNOME=	libsigc++20
PKGDIR=		${.CURDIR}
CMAKE_ARGS+=	-DUSE_QT:BOOL=YES \
		-DQT_ONLY:BOOL=YES

.include "${MASTERDIR}/Makefile"
