# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.4
CATEGORIES=	audio

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-msplugin --disable-strict
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org
GL_ACCOUNT=	BC/public
GL_PROJECT=	bcg729
GL_COMMIT=	9ada79d7ff53815e85432e7442810a2fd49dbd0e

.include <bsd.port.mk>
