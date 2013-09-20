# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	kcachegrind
PORTVERSION=	0.7.3
CATEGORIES=	devel kde
MASTER_SITES=	http://kcachegrind.sourceforge.net/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Profiling Visualization Tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

USES=		cmake gettext
USE_KDE4=	automoc4 kdehier kdelibs
USE_QT4=	moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOT VALGRIND
OPTIONS_DEFAULT=	DOT
DOT_DESC=	Use GraphViz/dot to render call graphs
VALGRIND_DESC=	Install devel/valgrind

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOT}
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if ${PORT_OPTIONS:MVALGRIND}
RUN_DEPENDS+=	valgrind:${PORTSDIR}/devel/valgrind
.endif

.include <bsd.port.mk>
