# New ports collection makefile for:	GLE
# Date created:				29 August 2000
# Whom:					David Gilbert <dgilbert@velocet.ca>
#
# $FreeBSD$
#

PORTNAME=	gle
PORTVERSION=	3.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://linas.org/gle/pub/ \
		http://metalab.unc.edu/pub/Linux/libs/X/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@dclg.ca
COMMENT=	A GL Tubing and Extrusion Library

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	"LIBS=-L${X11BASE}/lib -lXext ${PTHREAD_LIBS}"

MAN3=		gle.3gle gleExtrusion.3gle gleHelicoid.3gle gleLathe.3gle \
		glePolyCone.3gle glePolyCylinder.3gle gleScrew.3gle \
		gleSetJoinStyle.3gle gleSetNumSides.3gle gleSpiral.3gle \
		gleSuperExtrusion.3gle gleTextureMode.3gle gleToroid.3gle \
		gleTwistExtrusion.3gle

post-patch:
.for file in ex_angle.c ex_cut_round.c ex_raw.c extrude.c round_cap.c segment.c texgen.c
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/src/${file}
.endfor

.include <bsd.port.mk>
