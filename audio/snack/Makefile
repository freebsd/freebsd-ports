# ex:ts=8
# New ports collection makefile for:	snack
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	snack
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	audio tcl84 tk84
MASTER_SITES=	http://www.speech.kth.se/~kare/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Snack Sound Toolkit

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tk=${LOCALBASE}/lib/tk8.4 \
		--prefix=${PREFIX}

PLIST_SUB=	SNACK_VER=2.2

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-ogg-include=${LOCALBASE}/include \
			--with-ogg-lib=${LOCALBASE}/lib
ALL_TARGET=	all libsnackogg.so
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-everything::
.if !defined(WITH_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'Use "make WITH_VORBIS=yes" to build support for OGG Vorbis.'
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
