# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	0.3.7
CATEGORIES=	deskutils kde
MASTER_SITES=	ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/ \
		http://www.freehackers.org/~tnagy/kdissert/ \
		ftp://ftp.fasta.fh-dortmund.de/mirror/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons \
		gsed:${PORTSDIR}/textproc/gsed

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's:%%CXX%%:${CXX}:g ; \
		 s:%%CXXFLAGS%%:${CXXFLAGS} ${PTHREAD_CFLAGS}:g ; \
		 s:%%LINKFLAGS%%:${PTHREAD_LIBS}:g' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		's:|sed:|gsed:g' ${WRKSRC}/kde.py

do-configure:
	@cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" \
		QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}" scons configure

do-build:
	@cd ${WRKSRC} && scons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/kdissert/kdissert ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/kde3
	${INSTALL_DATA} ${WRKSRC}/src/templates/*.la ${PREFIX}/lib/kde3
	${INSTALL_DATA} ${WRKSRC}/src/templates/*.so ${PREFIX}/lib/kde3
	@${MKDIR} ${PREFIX}/share/applications/kde
	${INSTALL_DATA} ${WRKSRC}/src/appdata/kdissert.desktop \
		${PREFIX}/share/applications/kde
	@${MKDIR} ${PREFIX}/share/applnk/Utilities
	${INSTALL_DATA} ${WRKSRC}/src/appdata/kdissert.desktop \
		${PREFIX}/share/applnk/Utilities
	@${MKDIR} ${PREFIX}/share/apps/kdissert
	${INSTALL_DATA} ${WRKSRC}/src/appdata/kdissertui.rc \
		${PREFIX}/share/apps/kdissert
	${INSTALL_DATA} ${WRKSRC}/src/appdata/tips \
		${PREFIX}/share/apps/kdissert
	@${MKDIR} ${PREFIX}/share/apps/kdissert/pics
	${INSTALL_DATA} ${WRKSRC}/src/pics/nopix.png \
		${PREFIX}/share/apps/kdissert/pics
	@${MKDIR} ${PREFIX}/share/apps/kdissert/templatedata
	${INSTALL_DATA} ${WRKSRC}/src/templates/*.tar.gz \
		${PREFIX}/share/apps/kdissert/templatedata
	@${MKDIR} ${PREFIX}/share/apps/kdissertpart
	${INSTALL_DATA} ${WRKSRC}/src/appdata/kdissertpart.rc \
		${PREFIX}/share/apps/kdissertpart
	@${MKDIR} ${PREFIX}/share/config.kcfg
	${INSTALL_DATA} ${WRKSRC}/src/kdissert/kdissert.kcfg \
		${PREFIX}/share/config.kcfg
.for lang in en
	@${MKDIR} ${PREFIX}/share/doc/HTML/${lang}/kdissert
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/index.cache.bz2 \
		${PREFIX}/share/doc/HTML/${lang}/kdissert
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/index.docbook \
		${PREFIX}/share/doc/HTML/${lang}/kdissert
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/screenshot.png \
		${PREFIX}/share/doc/HTML/${lang}/kdissert
.endfor
.for lang in fr
	@${MKDIR} ${PREFIX}/share/doc/HTML/${lang}/kdissert
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/index.cache.bz2 \
		${PREFIX}/share/doc/HTML/${lang}/kdissert
	${INSTALL_DATA} ${WRKSRC}/doc/${lang}/index.docbook \
		${PREFIX}/share/doc/HTML/${lang}/kdissert
.endfor
.for size in 16 22 32 64 128
	@${MKDIR} ${PREFIX}/share/icons/crystalsvg/${size}x${size}/actions
	${INSTALL_DATA} ${WRKSRC}/src/pics/toolbar/cr${size}-action-kdissert_sort.png \
		${PREFIX}/share/icons/crystalsvg/${size}x${size}/actions/kdissert_sort.png
.endfor
.for size in 16 22 32
	@${MKDIR} ${PREFIX}/share/icons/crystalsvg/${size}x${size}/actions
	${INSTALL_DATA} ${WRKSRC}/src/pics/toolbar/cr${size}-action-kdissert_link.png \
		${PREFIX}/share/icons/crystalsvg/${size}x${size}/actions/kdissert_link.png
	${INSTALL_DATA} ${WRKSRC}/src/pics/toolbar/cr${size}-action-kdissert_point.png \
		${PREFIX}/share/icons/crystalsvg/${size}x${size}/actions/kdissert_point.png
.endfor
.for size in 16 22 32 64 128
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/src/appdata/hi${size}-app-kdissert.png \
		${PREFIX}/share/icons/hicolor/${size}x${size}/apps/kdissert.png
.endfor
.for lang in de fr nl pl
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.gmo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/kdissert.mo
.endfor
	@${MKDIR} ${PREFIX}/share/mimelnk/application
	${INSTALL_DATA} ${WRKSRC}/src/appdata/x-kdissert.desktop \
		${PREFIX}/share/mimelnk/application
	@${MKDIR} ${PREFIX}/share/services
	${INSTALL_DATA} ${WRKSRC}/src/appdata/kdissertpart.desktop \
		${PREFIX}/share/services

.include <bsd.port.mk>
