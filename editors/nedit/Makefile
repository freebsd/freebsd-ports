# New ports collection makefile for:	nedit
# Version required:			4.0.1
# Date created:				7 April 1996
#
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id:
#
DISTNAME=	nedit-4.0.1
CATEGORIES=	editors x11
MASTER_SITES=	ftp://ftp.fnal.gov/KITS/pub/nedit/v4_0_1/ \
		ftp://ftp.fnal.gov/KITS/pub/nedit/v4_0_1/contrib/
DISTFILES=	nedit_source.tar nedit.app-defaults 

MAINTAINER=	deischen@iworks.InterWorks.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_X11=	yes
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-C ${WRKDIR} -xf
EXTRACT_ONLY=	nedit_source.tar

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit

.include <bsd.port.mk>
