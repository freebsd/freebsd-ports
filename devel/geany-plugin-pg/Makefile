PORTNAME=	geany-plugin-pg
PORTVERSION=	${GEANY_VER}
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}
WWW=		https://plugins.geany.org/geanypg.html

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	gpg2:security/gnupg

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
