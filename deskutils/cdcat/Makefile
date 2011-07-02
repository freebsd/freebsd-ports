# New ports collection makefile for:	cdcat
# Date created: 			04 May 2006
# Whom: 				Aren Tyr <aren.tyr@gawab.com>
#
# $FreeBSD$
#

PORTNAME=	cdcat
PORTVERSION=	1.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A QT based tool for offline CD/DVD/disk catalogs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_WRKSRC=	${WRKSRC}/src

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qt3support xml \
		linguist_build moc_build qmake_build uic_build
MAKE_JOBS_SAFE=	yes

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

.include <bsd.port.pre.mk>

PORTDOCS=	Authors ChangeLog README TRANSLATORS_README
PLIST_FILES=	bin/cdcat \
		%%DATADIR%%/cdcat.png \
		%%DATADIR%%/translations/cdcat_cz.qm \
		%%DATADIR%%/translations/cdcat_de.qm \
		%%DATADIR%%/translations/cdcat_el.qm \
		%%DATADIR%%/translations/cdcat_es.qm \
		%%DATADIR%%/translations/cdcat_hu.qm \
		%%DATADIR%%/translations/cdcat_id.qm \
		%%DATADIR%%/translations/cdcat_pl.qm \
		%%DATADIR%%/translations/cdcat_pt.qm \
		%%DATADIR%%/translations/cdcat_sk.qm
PLIST_DIRS=	%%DATADIR%%/translations \
		%%DATADIR%%

do-configure:
	@${LRELEASE} ${BUILD_WRKSRC}/cdcat.pro
	@cd ${BUILD_WRKSRC} && ${QMAKE} cdcat.pro ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cdcat ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cdcat.png ${DATADIR}
	@${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/lang/*.qm ${DATADIR}/translations
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
