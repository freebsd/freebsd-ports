# New ports collection makefile for:	nedit
# Version required:			4.0.1
# Date created:				7 April 1996
#
# Whom:	Daniel Eischen <deischen@iworks.InterWorks.org>
#
# $Id: Makefile,v 1.4 1996/11/18 13:58:01 asami Exp $
#
DISTNAME=	nedit-4.0.3
CATEGORIES=	editors x11
MASTER_SITES=	ftp://ftp.fnal.gov/KITS/pub/nedit/v4_0_3/ \
		ftp://ftp.fnal.gov/KITS/pub/nedit/v4_0_3/contrib/
DISTFILES=	nedit_source.tar.gz nedit.app-defaults 

MAINTAINER=	deischen@iworks.InterWorks.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_X11=	yes
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-C ${WRKDIR} -xzf
EXTRACT_ONLY=	nedit_source.tar.gz
MAN1=		nedit.1 nc.1

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit

.include <bsd.port.mk>
