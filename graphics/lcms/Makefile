# New ports collection makefile for:	lcms
# Date created:		October 30, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.14
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.littlecms.com/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light Color Management System -- a color management library

USE_GNOME=	gnomehack gnometarget lthack
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--without-jpeg --without-tiff
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|^SUBDIRS =.*$$|SUBDIRS = src include|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3||g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in doc/LCMSAPI.TXT doc/TUTORIAL.TXT tifficc/tifficc.c \
	jpegicc/jpegicc.c jpegicc/iccjpeg.c samples/wtpt.c samples/icctrans.c
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-build test:
	cd ${WRKSRC}/testbed && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
