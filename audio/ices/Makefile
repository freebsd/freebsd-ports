# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	2.0.b.2.20030811
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://tigress.com/lofi/ \
		http://lofi.dyndns.org/
DISTNAME=	${PORTNAME}-2.0-Beta2-20030811

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming source client for icecast 2

LIB_DEPENDS=	shout.3:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/ices-2.0-Beta2

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ices-live.xml \
			${WRKSRC}/conf/ices-playlist.xml \
			${DOCSDIR}
.endif

.include <bsd.port.post.mk>
