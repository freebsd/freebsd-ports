# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peg-e
PORTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/peg-e/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Peg elimination game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib qmake tar:bzip2
USE_QT5=	core gui widgets qmake_build buildtools_build linguisttools_build
USE_GL=		gl
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
