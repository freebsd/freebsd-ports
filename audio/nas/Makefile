# New ports collection makefile for:	nas (formerly netaudio)
# Date created:		03 Nov 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}%20%28stable%29
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Network Audio System

USE_IMAKE=	yes
USE_XORG=	x11 xext xt xau sm ice xp xpm xmu xaw
USE_LDCONFIG=	yes
MAKE_ENV+=	COMPRESS_CMD="${COMPRESS_CMD:S/c//}"
MAKE_ARGS=	CC="${CC}" CXX="${CXX}"
MAKE_JOBS_UNSAFE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include "Makefile.man"

.include <bsd.port.pre.mk>
post-patch:
	@${FIND} ${WRKSRC} -name '*.c' | ${XARGS} ${GREP} -lF malloc.h \
		| ${XARGS} ${REINPLACE_CMD} -n -e "s|<malloc.h>||" -e t -e p

post-configure:
# Work around shortcomings of the Image.rules et. al:
	${REINPLACE_CMD} -e 's:-fPIC:${FPIC} -DPIC:g' \
	    -e 's,-c \$$(CCOPTIONS),-c $$(CFLAGS),' \
	    -e 's,\(\$$(AR) \$$@ \$$\)(OBJS),\1(OBJS:S|^|unshared/|),' \
		${WRKSRC}/lib/audio/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

.include <bsd.port.post.mk>
