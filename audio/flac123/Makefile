# New ports collection makefile for:	flac123
# Date created:		2004-05-14
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	flac123
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	flac-tools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line player for flac audio files

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		ao.3:${PORTSDIR}/audio/libao \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README.remote
PLIST_FILES=	bin/flac123

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
