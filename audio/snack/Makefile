# ex:ts=8
# New ports collection makefile for:	snack
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	snack
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	audio tcl83 tk83
MASTER_SITES=	http://www.speech.kth.se/~kare/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.3 \
		--with-tk=${LOCALBASE}/lib/tk8.3 \
		--prefix=${PREFIX}

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+= --with-ogg-include=${LOCALBASE}/include \
		 --with-ogg-lib=${LOCALBASE}/lib
ALL_TARGET=	all libsnackogg.so
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-everything:
.if !defined(WITH_VORBIS)
	@${ECHO}
	@${ECHO} 'Use "make WITH_VORBIS=yes" to build support for OGG Vorbis.'
	@${ECHO}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
