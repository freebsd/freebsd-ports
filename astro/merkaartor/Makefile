# New ports collection makefile for:   merkaartor
# Date created:        9 January 2009
# Whom:                slaven@rezic.de
#
# $FreeBSD$
#

PORTNAME=	merkaartor
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://www.merkaartor.org/downloads/source/

MAINTAINER=	slaven@rezic.de
COMMENT=	An openstreetmap mapping program

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2

USE_BZIP2=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build gui network svg webkit xml imageformats

MAN1=		merkaartor.1

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/merkaartor

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/merkaartor.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
