# New ports collection makefile for:	acm
# Version required:	comp.sources.x/volume12 (ver 2.0)
# Date created:		5 March 1995
# Whom:			joerg
#
# $Id: Makefile,v 1.13 1998/12/06 21:09:26 se Exp $
#

DISTNAME=	acm-4.8
CATEGORIES=	games
MASTER_SITES=	http://www.websimulations.com/download/

MAINTAINER=	se@FreeBSD.org

BROKEN='acm-5.0.tar.gz is all that is available' 

GNU_CONFIGURE=	yes
MAN6=		acm.6

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand exists() properly

# Include sound support (Use network audio server (nas))
.if defined(USE_SOUND) && ${USE_SOUND} == YES || \
    exists(${PREFIX}/lib/libaudio.a) && \
    (!defined(USE_SOUND) || ${USE_SOUND} != NO)
LIB_DEPENDS+=   audio.7:${PORTSDIR}/audio/nas
.endif

