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
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ijg.org/files/ \
		ftp://ftp.uu.net/graphics/jpeg/
DISTNAME=	jpegsrc.v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/jpeg-6b

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

ADDITIONAL_HEADER=	jinclude.h jpegint.h

# define J_MAXMEM like "make J_MAXMEM=32" to limit max processing memory to 32Mb
.if defined(J_MAXMEM)
CONFIGURE_ARGS+=	--enable-maxmem=$(J_MAXMEM)
.endif

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jpeg
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jpeg
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg
.endif
.for header in ${ADDITIONAL_HEADER}
	@${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include
.endfor

.include <bsd.port.mk>
