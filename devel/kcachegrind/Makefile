# New ports collection makefile for:	KCachegrind
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kcachegrind
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://kcachegrind.sourceforge.net/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Profiling Visualization Tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

OPTIONS=	DOT "Use GraphViz/dot to render call graphs" on \
		VALGRIND "Install devel/valgrind" off

.include <bsd.port.pre.mk>

.if defined (WITH_DOT)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if defined (WITH_VALGRIND)
RUN_DEPENDS+=	valgrind:${PORTSDIR}/devel/valgrind
.endif

.include <bsd.port.post.mk>
