# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast2
PORTVERSION=	2.3.2
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/ \
		http://svn.xiph.org/releases/icecast/
DISTNAME=	icecast-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A streaming mp3/ogg-vorbis audio server

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		shout.5:${PORTSDIR}/audio/libshout2 \
		speex.1:${PORTSDIR}/audio/speex \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		xslt.2:${PORTSDIR}/textproc/libxslt

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	icecast2
SUB_FILES+=	pkg-message
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include

DOCSDIR=	${PREFIX}/share/doc/icecast
WRKSRC=		${WRKDIR}/icecast-${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} \
		-e 's|SUBDIRS = src conf debian doc web admin win32 examples|SUBDIRS = src conf debian web admin win32 examples # doc|' \
		-e 's| install-exec-am install-data-am| install-exec-am|' ${WRKSRC}/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
