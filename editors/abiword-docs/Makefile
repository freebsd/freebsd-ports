PORTNAME=	abiword-docs
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/abiword/${PORTVERSION}/source/
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AbiWord help files
WWW=		https://www.abisource.com/

DEPRECATED=	abisource.com no longer exists
EXPIRATION_DATE=	2026-05-09

BUILD_DEPENDS=	abiword:editors/abiword
RUN_DEPENDS=	abiword:editors/abiword

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
# Don't give X warnings if DISPLAY is set
CONFIGURE_ENV=	DISPLAY=""
MAKE_ENV=	DISPLAY=""

.include <bsd.port.mk>
