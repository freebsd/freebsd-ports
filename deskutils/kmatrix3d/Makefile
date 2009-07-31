# New ports collection makefile for:   kmatrix
# Date created:        11 February 2007
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		kmatrix3d
PORTVERSION=		0.1
PORTREVISION=	5
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Eye candy for KDE, a new Matrix screensaver

DOCSDIR=		${PREFIX}/share/doc/HTML/en/kmatrix3d

WRKSRC=			${WRKDIR}/${PORTNAME}

USE_GL=			glut
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15 automake:19:env autoheader:262:env
USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${MAKE} -f admin/Makefile.common

.include <bsd.port.mk>
