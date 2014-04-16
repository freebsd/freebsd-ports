# Created by: David Gilbert <dgilbert@velocet.ca>
# $FreeBSD$

PORTNAME=	gle
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}\
		http://linas.org/gle/pub/ \
		http://metalab.unc.edu/pub/Linux/libs/X/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=	ports@dclg.ca
COMMENT=	A GL Tubing and Extrusion Library

USE_XORG=	ice xt xmu
USE_GL=		glut
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"LIBS=-L${LOCALBASE}/lib -lXext ${PTHREAD_LIBS}"

post-patch:
.for file in ex_angle.c ex_cut_round.c ex_raw.c extrude.c round_cap.c segment.c texgen.c
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/src/${file}
.endfor

.include <bsd.port.mk>
