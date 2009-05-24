# New ports collection makefile for:    qprog
# Date created:		2007/07/20
# Whom:			Brandon Fosdick <bfoz@bfoz.net>
#
# $FreeBSD$

PORTNAME=	qprog
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bfoz.net/projects/${PORTNAME}/release/
DISTNAME=	QProg_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Cross-platform software for the DIY line of PIC programmers

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build gui network

WRKSRC=		${WRKDIR}/QProg

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} QProg.pro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
