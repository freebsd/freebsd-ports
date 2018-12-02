# Created by: Brandon Fosdick <bfoz@bfoz.net>
# $FreeBSD$

PORTNAME=	qprog
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://bfoz.net/projects/${PORTNAME}/release/
DISTNAME=	QProg_${PORTVERSION}

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Cross-platform software for the DIY line of PIC programmers

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4 tar:tgz
USE_QT=		moc_build gui network

WRKSRC=		${WRKDIR}/QProg

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
