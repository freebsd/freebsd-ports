# New ports collection makefile for:	flac123
# Date created:		2004-05-14
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	flac123
PORTVERSION=	0.0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	flac-tools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line player for flac audio files

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ao.3:${PORTSDIR}/audio/libao \
		FLAC.5:${PORTSDIR}/audio/flac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/flac123
PORTDOCS=	README.remote

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
