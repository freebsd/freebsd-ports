# ex:ts=8
# New ports collection makefile for:	snack
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	snack
PORTVERSION=	2.2.9
CATEGORIES=	audio tcl84 tk84
MASTER_SITES=	http://www.speech.kth.se/~kare/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sound toolkit for scripting languages

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${DISTNAME}/unix

OPTIONS=	VORBIS "Support for OGG/Vorbis Audio" off

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}

CFLAGS+=	-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4 \
		-I${LOCALBASE}/include

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
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
