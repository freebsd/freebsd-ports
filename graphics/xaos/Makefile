# New ports collection makefile for:	XaoS
# Version required:			2.2
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $Id: Makefile,v 1.9 1998/11/29 12:43:08 asami Exp $
#

DISTNAME=	XaoS-3.0
PKGNAME=	xaos-3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.ta.jcu.cz/pub/linux/hubicka/XaoS/3.0/ \
		http://www.paru.cas.cz/~hubicka/XaoS/dist/
MASTER_SITE_SUBDIR=	graphics

MAINTAINER=	jkoshy@freebsd.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

USE_XLIB=	yes

# This port will benefit from all-stops-out optimization of the code

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS=-L${LOCALBASE}/lib

CFLAGS=		-DHAVE_SYS_PARAM_H \
		-I${PREFIX}/include \
		-pipe -O6 -fstrength-reduce -ffast-math -fomit-frame-pointer\
		-fforce-mem -fforce-addr -funroll-loops
MAN6=		xaos.6

post-install:
	strip ${PREFIX}/bin/xaos
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info ${PREFIX}/info/xaos.info ${PREFIX}/info/dir

.include <bsd.port.mk>
