# New ports collection makefile for:	nedit
# Version required:			5.0.2
# Date created:				7 April 1996
#
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.10 1998/03/28 14:36:34 steve Exp $
#

DISTNAME=	nedit-5.0.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.fnal.gov/KITS/pub/nedit/v5_0_2/ \
		ftp://ftp.fnal.gov/KITS/pub/nedit/v5_0_2/contrib/
DISTFILES=	nedit_source.tar.gz nedit.app-defaults

MAINTAINER=	deischen@iworks.InterWorks.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_X11=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	nedit_source.tar.gz
MAN1=		nedit.1 nc.1

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

.include <bsd.port.mk>
