# ex:ts=8
# New ports collection makefile for:	snack
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	snack
PORTVERSION=	2.2.10
PORTREVISION=	6
CATEGORIES=	audio tcl tk
MASTER_SITES=	http://www.speech.kth.se/snack/dist/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	simon@olofsson.de
COMMENT=	A sound toolkit for scripting languages

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

USE_TK=		84+

OPTIONS=	VORBIS "Support for OGG/Vorbis Audio" off

GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}

.include <bsd.port.pre.mk>
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}

CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} \
		-I${LOCALBASE}/include

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-ogg-include=${LOCALBASE}/include \
			--with-ogg-lib=${LOCALBASE}/lib
ALL_TARGET=	all libsnackogg.so
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
