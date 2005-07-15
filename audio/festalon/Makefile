# New ports collection makefile for:	festalon
# Date created:				13 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	festalon
PORTVERSION=	0.5.5
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/festalon/
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@critical.ch
COMMENT?=	A command line player for .nsf and .hes audio files

LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_LIBTOOL_VER=13
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 ppc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

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
