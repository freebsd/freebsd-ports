# Created by: shurd
# $FreeBSD$

PORTNAME=	qtel
PORTREVISION=	1

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Qtel Echolink client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libecholib.so:comms/svxlink \
		libgsm.so:audio/gsm

MASTERDIR=	${.CURDIR}/../svxlink
USES=		qt:4
USE_QT=		corelib gui network qmake_build linguist_build moc_build rcc_build uic_build
PKGDIR=		${.CURDIR}
CMAKE_ARGS+=	-DUSE_QT:BOOL=YES \
		-DQT_ONLY:BOOL=YES
USE_GNOME=	libsigc++20

.include "${MASTERDIR}/Makefile"
