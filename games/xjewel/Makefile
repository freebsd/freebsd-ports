# New ports collection makefile for:    xjewel
# Version required:     1.6
# Date created:         22 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1995/04/11 02:00:37 jmz Exp $
#

DISTNAME=	xjewel-1.6
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/x11/
DISTFILES=	xjewel-1.6.tar.z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/xjewel.font
	@mkdir -p ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)
	@(cd ${WRKSRC}/bitmaps/; install -c seven_seg.pcf.Z fonts.dir \
		${PREFIX}/lib/xjewel.font)

do-install:
	@(mv ${PREFIX}/bin/xjewel ${PREFIX}/bin/xjewel_; \
	  echo "#!/bin/sh" >${PREFIX}/bin/xjewel; \
	  echo "xset +fp ${PREFIX}/lib/xjewel.font" >>${PREFIX}/bin/xjewel; \
	  echo "xjewel_" >>${PREFIX}/bin/xjewel; \
	  chmod ugo+x ${PREFIX}/bin/xjewel)

.include <bsd.port.mk>
