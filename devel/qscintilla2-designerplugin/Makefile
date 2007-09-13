# New ports collection makefile for:	qscintilla2-designerplugin
# Date created:				2007-02-09
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	2.1
PORTEPOCH=	1
PORTREVISION=	# zero
CATEGORIES=	devel
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/QScintilla2/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	qscintilla2-
DISTNAME=	QScintilla-1.73-gpl-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Qt Designer plugin for QScintilla2 (Qt4)

LIB_DEPENDS=	qscintilla2.2:${PORTSDIR}/devel/qscintilla2

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui xml designer
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/designer-Qt4

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} designer.pro

.include <bsd.port.post.mk>
