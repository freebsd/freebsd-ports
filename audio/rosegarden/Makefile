# New ports collection makefile for:	rosegarden
# Version required:	2.0.1
# Date created:		04 Aug 1996
# Whom:			shanee
#
# $Id: Makefile,v 1.4 1997/09/08 12:25:15 tg Exp $
#

DISTNAME=	rosegarden-2.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/ROSE/
EXTRACT_SUFX=	-sources.tgz

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	Xaw3d\\.6\\.:$(PORTSDIR)/x11-toolkits/Xaw3d
RUN_DEPENDS=	playmidi:${PORTSDIR}/audio/playmidi

ALL_TARGET=	all ROSEGARDEN=$(WRKSRC) SYSLIBS="\"-lXaw3d -lXext -lXmu -lXt -lX11\"" SYSEXTRALIBS=""

WRKSRC=		${WRKDIR}/rosegarden
MAKEFILE=	Makefile.FreeBSD
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"

.include <bsd.port.mk>
