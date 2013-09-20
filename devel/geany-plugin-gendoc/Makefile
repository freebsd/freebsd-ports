# $FreeBSD$

PORTNAME=	geany-plugin-gendoc
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	ctpl:${PORTSDIR}/textproc/ctpl
RUN_DEPENDS=	${LOCALBASE}/bin/rst2html:${PORTSDIR}/textproc/py-docutils

NO_STAGE=	yes
.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
