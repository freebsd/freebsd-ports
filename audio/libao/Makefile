# New ports collection makefile for:	libao
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libao
PORTVERSION=	0.8.2
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/ \
		http://www.vorbis.com/files/rc3/unix/ \
		http://www.oddsock.org/vorbisrc3/files/rc3/unix/

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
LIB_DEPENDS=	artsc.0:${PORTSDIR}/x11/kdelibs2
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
.endif

.include <bsd.port.post.mk>
