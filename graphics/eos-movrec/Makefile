# New ports collection makefile for:	EOS camera movie record
# Date created:				15 Aug 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eos-movrec
DISTVERSION=	0.3.1_beta
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.3_beta

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A program to capture short movies with Canon DSLR camera

LICENSE=	GPLv2

LIB_DEPENDS=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_ZIP=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build gui

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
DISTVERSIONSUFFIX=	-src

PLIST_FILES=	bin/eos_movrec

post-patch:
	@${REINPLACE_CMD} -e 's,GLIBC,FreeBSD,' ${WRKSRC}/os_api.h

.include <bsd.port.mk>
