# $FreeBSD$

PORTNAME=	geany-plugin-spellcheck
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

NO_STAGE=	yes
.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
