# New ports collection makefile for:	acm
# Version required:	comp.sources.x/volume12 (ver 2.0)
# Date created:		5 March 1995
# Whom:			joerg
#
# $Id: Makefile,v 1.11 1997/07/10 01:43:01 asami Exp $
#

DISTNAME=	acm-4.7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/x11/

MAINTAINER=	joerg@FreeBSD.org

BROKEN_ELF=	build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	${SH} -x	# don't ask me why, will fail otherwise
STRIP=
MAN6=		acm.6

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand exists() properly

# Include sound support (Use network audio server (nas))
.if defined(USE_SOUND) && ${USE_SOUND} == YES || \
    exists(${PREFIX}/lib/libaudio.a) && \
    (!defined(USE_SOUND) || ${USE_SOUND} != NO)
LIB_DEPENDS+=   audio.7:${PORTSDIR}/audio/nas
.endif

