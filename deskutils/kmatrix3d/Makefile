# New ports collection makefile for:   kmatrix
# Date created:        11 February 2007
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		kmatrix3d
PORTVERSION=		0.1
PORTREVISION=	10
CATEGORIES=		deskutils
MASTER_SITES=		SF

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Eye candy for KDE, a new Matrix screensaver

LIB_DEPENDS=		png15:${PORTSDIR}/graphics/png

DOCSDIR=		${PREFIX}/share/doc/HTML/en/kmatrix3d

WRKSRC=			${WRKDIR}/${PORTNAME}

USE_GL=			glu glut
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool automake:env autoheader:env
USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
CFLAGS+=		-I${LOCALBASE}/include/libpng15

AUTOTOOLSFILES=		admin/cvs.sh

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${MAKE} -f admin/Makefile.common

.include <bsd.port.mk>
