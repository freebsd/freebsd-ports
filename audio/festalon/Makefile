# New ports collection makefile for:	festalon
# Date created:				13 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	festalon
PORTVERSION=	0.5.5
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/festalon/ \
		CRITICAL
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT?=	A command line player for .nsf and .hes audio files

LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 ppc

.include <bsd.port.pre.mk>

.if ${PKGNAMEPREFIX} == ""

USE_SDL=	yes

PLIST_FILES=	bin/festalon
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
