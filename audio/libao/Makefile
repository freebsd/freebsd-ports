# New ports collection makefile for:	libao
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libao
PORTVERSION=	0.8.5
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/ao/src/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Portable audio output library

WANT_GNOME=	yes
USE_GNOME=	gnomehack pkgconfig
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

MAN5=		libao.conf.5

.if defined(WITH_ARTS)
LIB_DEPENDS=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUB+=	ARTS="@comment "
pre-everything::
	@${ECHO_MSG} "Define WITH_ARTS to enable the aRts module."
.endif

.if defined(WITH_NAS)
LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas
PLIST_SUB+=	NAS=""
.else
CONFIGURE_ARGS+=	--disable-nas
PLIST_SUB+=	NAS="@comment "
pre-everything::
	@${ECHO_MSG} "Define WITH_NAS to enable the NAS module."
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND=""
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.include <bsd.port.post.mk>
