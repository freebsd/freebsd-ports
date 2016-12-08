# Created by: cy
# $FreeBSD$

PORTNAME=	qxv
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES+=	graphics
MASTER_SITES=	http://labs.freehackers.org/attachments/download/422/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Qt 4 program that displays images of various formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:bzip2
USE_QT4=	corelib gui moc_build uic_build rcc_build
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
