# Created by: ijliao
# $FreeBSD$

PORTNAME=	snack
PORTVERSION=	2.2.10
PORTREVISION=	6
CATEGORIES=	audio tcl tk
MASTER_SITES=	http://www.speech.kth.se/snack/dist/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound toolkit for scripting languages

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

OPTIONS_DEFINE=	VORBIS DOCS
OPTIONS_SUB=	yes

USES=		tk
USE_LDCONFIG=	${PREFIX}/lib/snack${PORTVERSION:R}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR}
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-ogg-include=${LOCALBASE}/include \
		--with-ogg-lib=${LOCALBASE}/lib
ALL_TARGET=	all libsnackogg.so
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
