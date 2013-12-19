# Created by: ijliao
# $FreeBSD$

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
NO_STAGE=	yes

OPTIONS_DEFINE=	VORBIS DOCS

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}

CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} \
		-I${LOCALBASE}/include

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-ogg-include=${LOCALBASE}/include \
			--with-ogg-lib=${LOCALBASE}/lib
ALL_TARGET=	all libsnackogg.so
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
