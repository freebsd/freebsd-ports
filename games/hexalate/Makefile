# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hexalate
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Color matching game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib qmake tar:bzip2
USE_QT5=	core gui widgets buildtools_build linguisttools_build
USE_GL=		gl
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
