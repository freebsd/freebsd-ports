# $FreeBSD$

PORTNAME=	geany-plugin-workbench
PORTVERSION=	${GEANY_VER}
PORTREVISION=	2
CATEGORIES=	devel

PATCH_SITES=	https://github.com/geany/geany-plugins/commit/
PATCHFILES=	9497d829e1b207eb83575dc6f617feecfb89bc16.patch:-p1

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libgit2.so:devel/libgit2

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
