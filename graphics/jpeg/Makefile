# New ports collection makefile for:	jpeg
# Date created:		6 November 1994
# Whom:			smace
#
# $FreeBSD$
#
# PLEASE update print/ghostscript5 (there's a symlink that uses a hardwired
# version number) when updating this port.  Thank you.

PORTNAME=	jpeg
PORTVERSION=	6b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.uu.net/graphics/jpeg/
DISTNAME=	jpegsrc.v${PORTVERSION}

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/jpeg-6b

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg
.endif

.include <bsd.port.mk>
