# New ports collection Makefile for:	kdesdk
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdesdk
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier \
		automoc4 akonadi
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	network gui svg qt3support \
		qmake_build moc_build rcc_build uic_build \
		porting_build uic3_build
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	adddebug.1 \
	cervisia.1 \
	cheatmake.1 \
	create_cvsignore.1 \
	create_makefile.1 \
	create_makefiles.1 \
	cvscheck.1 \
	cvslastchange.1 \
	cvslastlog.1 \
	cvsrevertlast.1 \
	cxxmetric.1 \
	demangle.1 \
	extend_dmalloc.1 \
	extractrc.1 \
	fixincludes.1 \
	kate.1 \
	po2xml.1 \
	pruneemptydirs.1 \
	qtdoc.1 \
	reportview.1 \
	split2po.1 \
	swappo.1 \
	transxx.1 \
	xml2pot.1 \
	zonetab2pot.py.1

.include <bsd.port.mk>
