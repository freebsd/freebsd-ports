# New ports collection makefile for:	qcomicbook
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcomicbook
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://linux.bydg.org/~yogin/qcomicbook/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	QT-based comic book archive viewer

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
# USE_EFL=	imlib2 #disabled in this release
GNU_CONFIGURE=	yes

MAN1=		qcomicbook.1

DESKTOP_ENTRIES="QComicBook" "Comic Book Viewer" \
		"${DATADIR}/${PORTNAME}.png" \
		"qcomicbook" "" false

.include <bsd.port.mk>
