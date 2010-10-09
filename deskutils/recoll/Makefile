# New ports collection makefile for:   recoll
# Date created:        5 December 2005
# Whom:                J.F. Dockes <jean-francois.dockes@wanadoo.fr>
#
# $FreeBSD$
#

PORTNAME=	recoll
PORTVERSION=	1.14.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	jf@dockes.org
COMMENT=	A personal full text search package, based on QT and Xapian

LIB_DEPENDS=	xapian.[1-2][0-9]:${PORTSDIR}/databases/xapian-core

USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build uic_build moc_build rcc_build \
		qt3support uic3_build porting
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
