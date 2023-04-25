PORTNAME=	hpsjam
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.7
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Online jamming client and server tool
WWW=		https://github.com/hselasky/hpsjam

LICENSE=	BSD2CLAUSE

LIB_DEPENDS= \
	libjack.so:audio/jack

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools:build core gui widgets svg

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky
GH_TUPLE=	mborgerding:kissfft:131.1.0:a/kissfft

USER=           nobody
SUB_LIST=       USER=${USER}
USE_RC_SUBR=    ${PORTNAME}_server

PLIST_FILES= \
	bin/HpsJam \
	share/pixmaps/HpsJam.png \
	share/applications/HpsJam.desktop

.include <bsd.port.mk>
