# New ports collection makefile for:	GLE
# Date created:				29 August 2000
# Whom:					David Gilbert <dgilbert@velocet.ca>
#
# $FreeBSD$
#

PORTNAME=	gle
PORTVERSION=	3.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://linas.org/gle/ \
		http://metalab.unc.edu/pub/Linux/libs/X/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dgilbert@velocet.ca

USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	"LIBS=-L${X11BASE}/lib -lXext"

MAN3=		gle.3gle gleExtrusion.3gle gleHelicoid.3gle gleLathe.3gle \
		glePolyCone.3gle glePolyCylinder.3gle gleScrew.3gle \
		gleSetJoinStyle.3gle gleSetNumSides.3gle gleSpiral.3gle \
		gleSuperExtrusion.3gle gleTextureMode.3gle gleToroid.3gle \
		gleTwistExtrusion.3gle

.include <bsd.port.mk>
