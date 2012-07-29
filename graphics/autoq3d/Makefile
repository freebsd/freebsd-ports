# New ports collection makefile for:	autoq3d
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autoq3d
DISTVERSION=	1.40
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AutoQ3D%20${PORTVERSION}
DISTNAME=	AutoQ3DCommunity${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete QT quick 3D model editor program

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GL=		glu
USE_ZIP=	yes
USE_QT4=	corelib gui opengl \
		moc_build qmake_build
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES=	"AutoQ3D" \
			"A complete QT quick 3d model editor program" \
			"AutoQ3D" \
			"AutoQ3D" \
			"Qt;KDE;Graphics;" \
			"false"

post-patch:
.for file in src/main.cpp src/fgui/cadform.cpp src/dialogs/prgsettings.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share/AutoQ3D-Community|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}/images
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
