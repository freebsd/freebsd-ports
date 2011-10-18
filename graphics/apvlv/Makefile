# New ports collection makefile for: apvlv
# Date created:                03 May 2010
# Whom:                        Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apvlv
PORTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://cloud.github.com/downloads/naihe2010/apvlv/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	xors@imap.cc
COMMENT=	Apvlv is a PDF/DJVU Viewer and its behaviour like Vim

LICENSE=	GPLv2

LIB_DEPENDS=	poppler-glib.6:${PORTSDIR}/graphics/poppler-gtk

USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc \
		-DMANDIR=${MANPREFIX}/man \
		-DDOCDIR=${DOCSDIR} \
		-DAPVLV_WITH_UMD=OFF

MAN1=		apvlv.1

OPTIONS=	DJVU	"Enable DJVU support"	off

.include <bsd.port.options.mk>

.if defined(WITHOUT_DJVU)
CMAKE_ARGS+=	-DAPVLV_WITH_DJVU=OFF
.else
CMAKE_ARGS+=	-DAPVLV_WITH_DJVU=ON
LIB_DEPENDS+=	djvulibre.24:${PORTSDIR}/graphics/djvulibre-nox11
.endif

.include <bsd.port.mk>
