# New ports collection makefile for:	qcomicbook
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcomicbook
PORTVERSION=	0.4.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://linux.bydg.org/~yogin/qcomicbook/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	QT-based comic book archive viewer

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
# USE_EFL=	imlib2 #disabled in this release
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		qcomicbook.1

DESKTOP_ENTRIES="QComicBook" "Comic Book Viewer" \
		"${DATADIR}/${PORTNAME}.png" \
		"qcomicbook" "" false

OPTIONS=	7ZIP "Enable support for 7-Zip (.cb7) comic book archives" on \
		ACE "Enable support for ACE (.cba) comic book archives" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
CPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
.endif

# 7-Zip (.cb7) support
.if !defined(WITHOUT_7ZIP)
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

# ACE (.cba) support
.if !defined(WITHOUT_ACE)
RUN_DEPENDS+=	unace:${PORTSDIR}/archivers/unace
.endif

.include <bsd.port.post.mk>
