# New ports collection makefile for:	rosegarden
# Version required:	2.0b3
# Date created:		04 Aug 1996
# Whom:			shanee
#
# $Id: Makefile,v 1.2 1996/08/08 00:22:40 chuckr Exp $
#

DISTNAME=	rosegarden
PKGNAME=	rosegarden-2.0
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/ROSE/
CATEGORIES=	audio
EXTRACT_SUFX=	-2.0-BETA3-sources.tgz

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	Xaw3d\\.6\\.:$(PORTSDIR)/x11/Xaw3d
RUN_DEPENDS=	playmidi:${PORTSDIR}/audio/playmidi

ALL_TARGET=	all ROSEGARDEN=$(WRKSRC) SYSLIBS="\"-lXaw3d -lXext -lXmu -lXt -lX11\"" SYSEXTRALIBS=""

.include <bsd.port.mk>
