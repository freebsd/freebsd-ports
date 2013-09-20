# $FreeBSD$

PORTNAME=	geany-plugin-pg
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme
RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

NO_STAGE=	yes
.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
