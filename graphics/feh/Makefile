# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	1.3.4
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	An image viewer that utilizes Imlib2

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

USE_XORG=	x11 xt xinerama
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		feh.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${PERL} -pi.bak -e \
		's|^CFLAGS="-I|#CFLAGS="-I|g ; \
		 s|^LIBS="-L|#LIBS="-L|g' ${WRKSRC}/configure
	@${PERL} -pi.bak -e \
		's|-man install-docsDATA|-man|g' ${WRKSRC}/Makefile.in
	@${PERL} -pi.bak -e \
		's|^#!/bin/bash|#!/bin/sh|g' ${WRKSRC}/cam/gen_cam_menu.sh
	@${PERL} -pi.bak -e \
		's|^LDFLAGS.*$$|LDFLAGS = \@LDFLAGS\@|g ; \
		 s|-I/usr/X11R6/include||g ; \
		 s|-I/usr/local/include/libpng||g ; \
		 s| getopt\.[cho]||g ; \
		 s| getopt1\.[co]||g ; \
		 s|^getopt|#getopt|g' ${WRKSRC}/src/Makefile.in
	@${PERL} -pi.bak -e \
		's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/src/feh.h
	@${PERL} -pi.bak -e \
		's|wprintf|weprintf|g' ${WRKSRC}/src/support.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
