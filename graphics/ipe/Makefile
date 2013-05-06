# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	ipe
DISTVERSION=	7.1.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}7/${PORTNAME}/7.1.0
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible drawing editor

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_LUA=	5.1
USE_GMAKE=	yes
USE_QT4=	gui qt3support qmake_build moc_build uic_build rcc_build
USE_TEX=	tetex
MAN1=		ipe.1 ipe6upgrade.1 ipeextract.1 iperender.1 ipetoipe.1 ipescript.1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-ipe__Makefile
.endif

PLIST_SUB+=	VERSION="${DISTVERSION}"

post-install:
	cd ${WRKSRC}/../fontmaps && ${MKDIR} ${DATADIR}/${DISTVERSION} && \
	${SED} s,/usr/share/fonts/type1/gsfonts,${PREFIX}/share/ghostscript/fonts, \
	< gsfonts-fontmap.xml > ${DATADIR}/${DISTVERSION}/fontmap.xml

.include <bsd.port.mk>
