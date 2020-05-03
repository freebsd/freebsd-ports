# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	tetzle
PORTVERSION=	2.1.6
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/tetzle/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Jigsaw puzzle with tetrominoes

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib desktop-file-utils gl gnome qmake qt:5 tar:bzip2
USE_QT=		core gui widgets buildtools_build linguisttools_build
USE_GL=		gl
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
