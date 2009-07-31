# New ports collection makefile for:   recoll
# Date created:        5 December 2005
# Whom:                J.F. Dockes <jean-francois.dockes@wanadoo.fr>
#
# $FreeBSD$
#

PORTNAME=	recoll
PORTVERSION=	1.12.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	jean-francois.dockes@wanadoo.fr
COMMENT=	A personal full text search package, based on QT and Xapian

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	xapian.[1-2][0-9]:${PORTSDIR}/databases/xapian-core \
		qt-mt.3:${PORTSDIR}/x11-toolkits/qt33

USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC="freebsd-g++"
MAKE_ENV=	${CONFIGURE_ENV}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
INSTALLS_ICONS=	yes

MAN1=		recoll.1 recollindex.1
MAN5=		recoll.conf.5

post-patch:
	${REINPLACE_CMD} -e 's/^CXXFLAGS =/CXXFLAGS ?=/' \
		${WRKSRC}/mk/localdefs.in

.include <bsd.port.mk>
