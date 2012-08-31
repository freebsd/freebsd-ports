# New ports collection makefile for:	Qross
# Date created:				2012-01-08
# Whom:				Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qross
PORTVERSION=	0.2.2
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/0xd34df00d/Qross/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Qt-only fork of Kross, the KDE scripting framework

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_QT4=	designer gui network xml qmake_build uic_build moc_build \
		rcc_build script

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/qross

post-install:
.for lib in libqrossui libqrosscore qrossqts
	@${LN} -s ${lib}.so.0.1 ${PREFIX}/lib/${lib}.so.1
.endfor

.include <bsd.port.mk>
