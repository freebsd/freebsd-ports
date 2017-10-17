# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-notify
DISTVERSIONPREFIX=      v
DISTVERSION=    1.3.0
DISTVERSIONSUFFIX=	-p1
CATEGORIES=	deskutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Alarm/notification utility from the Lumina Desktop

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	I18N
OPTIONS_DEFAULT=	I18N
I18N_DESC= Install localization files

.include <bsd.port.options.mk>

MAKE_JOBS_UNSAFE=yes

USE_QT5=	core gui widgets network svg \
		buildtools_build x11extras concurrent multimedia
USES=		qmake
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina
WRKSRC_SUBDIR=	src-qt5/desktop-utils/${PORTNAME}

.if${PORT_OPTIONS:MI18N}
USE_QT5+= linguist_build
QMAKE_ARGS+=CONFIG+=WITH_I18N
.endif

.include <bsd.port.mk>
