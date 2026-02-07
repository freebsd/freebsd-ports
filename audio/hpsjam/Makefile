PORTNAME=	hpsjam
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.8
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online jamming client and server tool
WWW=		https://github.com/hselasky/hpsjam

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	hselasky
GH_TUPLE=	mborgerding:kissfft:131.1.0:a/kissfft
USE_GL=		gl
USE_QT=		core gui svg widgets buildtools:build
USE_RC_SUBR=	${PORTNAME}_server

USER=		nobody
SUB_LIST=	USER=${USER}

PLIST_FILES=	bin/HpsJam \
		share/applications/HpsJam.desktop \
		share/pixmaps/HpsJam.png

.include <bsd.port.mk>
