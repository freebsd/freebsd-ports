# New ports collection makefile for:	acm
# Version required:	comp.sources.x/volume12 (ver 2.0)
# Date created:		5 March 1995
# Whom:			joerg
#
# $Id: Makefile,v 1.8 1996/11/18 11:24:18 asami Exp $
#

DISTNAME=	acm-4.7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/x11/

MAINTAINER=	joerg@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX}
STRIP=
MAN1=		acm.1

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand exists() properly

# Include sound support (Use network audio server (nas))
.if defined(USE_SOUND) && ${USE_SOUND} == YES || \
    exists(${PREFIX}/lib/libaudio.a) && \
    (!defined(USE_SOUND) || ${USE_SOUND} != NO)
LIB_DEPENDS+=   audio\\.7\\.:${PORTSDIR}/audio/nas
.endif

