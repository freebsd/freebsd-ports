# New ports collection makefile for:	libao
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libao
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wiles.org/pub/mirrors/Vorbis/unix/ \
		http://www.oddsock.org/vorbis/unix/ \
		http://www.casterclub.com/vorbis/unix/ \
		http://www.math.utoledo.edu/~chaese/Vorbis/unix/

MAINTAINER=	naddy@FreeBSD.org

USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

MAN5=		libao.conf.5

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND=""
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+= --disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

# XXX  This needs a better check.
.if exists(${LOCALBASE}/bin/artsc-config)
LIB_DEPENDS=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
CONFIGURE_ARGS+= --disable-arts
.endif

.include <bsd.port.post.mk>
