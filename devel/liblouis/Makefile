# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	2.6.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-source Braille Translator And Back-translator

LICENSE=	LGPL3+

BUILD_DEPENDS=	help2man:misc/help2man

USES=		autoreconf gmake libtool pathfix
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
