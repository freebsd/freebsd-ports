# New ports collection makefile for:    xjewel
# Version required:     1.6
# Date created:         22 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	xjewel-1.6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/x11/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xjewel.6

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/xjewel
	@${MKDIR} ${PREFIX}/man/man6
	@(cd ${WRKSRC}/bitmaps/; ${INSTALL_DATA} seven_seg.pcf.gz fonts.dir \
		${PREFIX}/lib/X11/xjewel)

post-install:
	@(${MV} ${PREFIX}/bin/xjewel ${PREFIX}/bin/xjewel_; \
	$(ECHO) "#!/bin/sh" >${PREFIX}/bin/xjewel; \
	$(ECHO) "xset +fp ${PREFIX}/lib/X11/xjewel" >>${PREFIX}/bin/xjewel; \
	$(ECHO) "${PREFIX}/bin/xjewel_" >>${PREFIX}/bin/xjewel; \
	${CHMOD} ugo+x ${PREFIX}/bin/xjewel)

.include <bsd.port.mk>
