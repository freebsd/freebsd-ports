# New ports collection makefile for:	playmidi
# Date created:		27 Feb 1995
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	playmidi
PORTVERSION=	2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI player

WRKSRC=		${WRKDIR}/${PORTNAME}-2.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500014
EXTRA_PATCHES=	${FILESDIR}/extra-*
.endif

ONLY_FOR_ARCHS=	i386
IS_INTERACTIVE=	YES	# asks what devices you want to support
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=	PREFIX=${PREFIX}
INSTALL_TARGET=	install.lame install.man
MAN1=		playmidi.1

.include <bsd.port.post.mk>
