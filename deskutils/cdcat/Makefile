# New ports collection makefile for:	cdcat
# Date created: 			04 May 2006
# Whom: 				Aren Tyr <aren.tyr@gawab.com>
#
# $FreeBSD$
#

PORTNAME=	cdcat
PORTVERSION=	1.01b	# >1.01 as b doesn't stay for 'beta'
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://cdcat.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CdCat-${PORTVERSION}

MAINTAINER=	aren.tyr@gawab.com
COMMENT=	A QT based tool for offline CD/DVD/disk catalogs

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/CdCat-${PORTVERSION}/src

USE_BZIP2=	yes
USE_QT_VER=	3
QTDIR?=		${QT_PREFIX}
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QTDIR}" MAKE="${GMAKE}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"

#PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/cdcat \
		share/cdcat/Authors \
		share/cdcat/COPYING \
		share/cdcat/ChangeLog \
		share/cdcat/README \
		share/cdcat/TRANSLATORS_README \
		share/cdcat/cdcat.png \
		share/cdcat/translations/cdcat_cz.qm \
		share/cdcat/translations/cdcat_de.qm \
		share/cdcat/translations/cdcat_el.qm \
		share/cdcat/translations/cdcat_es.qm \
		share/cdcat/translations/cdcat_fr.qm \
		share/cdcat/translations/cdcat_hu.qm \
		share/cdcat/translations/cdcat_id.qm \
		share/cdcat/translations/cdcat_it.qm \
		share/cdcat/translations/cdcat_pl.qm \
		share/cdcat/translations/cdcat_pt.qm \
		share/cdcat/translations/cdcat_sk.qm \
		share/cdcat/translations/cdcat_sr.qm
PLIST_DIRS=	share/cdcat/translations \
		share/cdcat

post-patch:
	@${REINPLACE_CMD} -e 's|importGtktalogCsv\:\:importGtktalogCsv|importGtktalogCsv|' \
		${WRKSRC}/import.h

pre-configure:
	cd ${WRKSRC} && ${MAKE_ENV} qmake cdcat.pro
.if defined(WITH_KDE)
PLIST_DIRS+=		share/apps/cdcat
PLIST_FILES+=		share/applications/kde/cdcat.desktop \
			share/apps/cdcat/cdcat.png
.endif

post-install:
.if defined(WITH_KDE)
	${INSTALL_DATA} ${WRKSRC}/../KDE/cdcat.desktop ${LOCALBASE}/share/applications/kde
	${MKDIR} ${LOCALBASE}/share/apps/cdcat
	${LN} ${LOCALBASE}/share/cdcat/cdcat.png ${LOCALBASE}/share/apps/cdcat
.endif

	${STRIP_CMD} ${LOCALBASE}/bin/cdcat

.include <bsd.port.post.mk>
