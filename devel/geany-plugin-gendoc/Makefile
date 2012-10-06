# $FreeBSD$

PORTNAME=	geany-plugin
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	ctpl:${PORTSDIR}/textproc/ctpl
RUN_DEPENDS=	${LOCALBASE}/bin/rst2html:${PORTSDIR}/textproc/py-docutils

GEANY_PLUGIN=	gendoc
GEANY_PLUGIN_DIR=	geanygendoc

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
