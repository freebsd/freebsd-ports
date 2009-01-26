# New ports collection makefile for:	canna-lib
# Date created:		7 September 2008
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	canna
PORTVERSION=	3.7p3
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	canna/9565/
PKGNAMESUFFIX=	-lib
DISTNAME=	Canna${PORTVERSION:S/.//g}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Kana-to-Kanji conversion system, library part

# XXX: USE_IMAKE implies USE_XLIB which is not needed for this port
BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

USE_BZIP2=	yes
USE_LDCONFIG=	yes
NO_INSTALL_MANPAGES=yes

ALL_TARGET=	canna
INSTALL_TARGET=	instsgs

post-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

.include <bsd.port.mk>
