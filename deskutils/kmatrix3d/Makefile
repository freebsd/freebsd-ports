# New ports collection makefile for:   kmatrix
# Date created:        11 February 2007
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		kmatrix3d
PORTVERSION=		0.1
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Eye candy for KDE, a new Matrix screensaver

LIB_DEPENDS=		glut.4:${PORTSDIR}/graphics/libglut

DOCSDIR=		${PREFIX}/share/doc/HTML/en/kmatrix3d/

WRKSRC=			${WRKDIR}/${PORTNAME}

USE_GL=			yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15 automake:19:env autoheader:259:env
USE_KDELIBS_VER=	3
USE_BZIP2=		yes

pre-configure:
	cd ${WRKSRC} && ${MAKE} -f admin/Makefile.common

MANCOMPRESSED=		yes

.include <bsd.port.mk>
