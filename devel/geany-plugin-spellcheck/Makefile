# $FreeBSD$

PORTNAME=	geany-plugin-spellcheck
PORTVERSION=	${GEANY_VER}
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
