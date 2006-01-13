# New ports collection makefile for:   recoll
# Date created:        5 December 2005
# Whom:                J.F. Dockes <jean-francois.dockes@wanadoo.fr>
#
# $FreeBSD$
#

PORTNAME=	recoll
PORTVERSION=	1.1.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	jean-francois.dockes@wanadoo.fr
COMMENT=	A personal full text search package, based on QT and Xapian

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	xapian.8:${PORTSDIR}/databases/xapian-core \
		qt-mt.3:${PORTSDIR}/x11-toolkits/qt33

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}" QMAKESPEC="freebsd-g++"
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		recoll.1 recollindex.1
MAN5=		recoll.conf.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
