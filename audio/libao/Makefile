# New ports collection makefile for:	libao
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libao
PORTVERSION=	0.8.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.linuxpowered.com/pub/Vorbis/unix/ \
		ftp://ftp.wiles.org/pub/mirrors/Vorbis/unix/ \
		http://xiph.stratius.com/vorbis/unix/ \
		http://www.oddsock.org/vorbis/unix/ \
		http://www.casterclub.com/vorbis/unix/ \
		http://www.math.utoledo.edu/~chaese/Vorbis/unix/

MAINTAINER=	naddy@FreeBSD.org

WANT_ESOUND=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

MAN5=		libao.conf.5

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
PLIST_SUB=	ESOUND=""
.else
PLIST_SUB=	ESOUND="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config)
LIB_DEPENDS=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
.endif

.include <bsd.port.post.mk>
