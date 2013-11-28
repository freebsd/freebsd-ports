# Created by: Brandon Fosdick <bfoz@bfoz.net>
# $FreeBSD$

PORTNAME=	qprog
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://bfoz.net/projects/${PORTNAME}/release/
DISTNAME=	QProg_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Cross-platform software for the DIY line of PIC programmers

USES=		qmake
USE_QT4=	moc_build gui network

WRKSRC=		${WRKDIR}/QProg

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
