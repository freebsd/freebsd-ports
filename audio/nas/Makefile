# New ports collection makefile for:	nas (formerly netaudio)
# Date created:		03 Nov 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	nas
PORTVERSION=	1.7c
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Audio System

USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	-Werror
MAKE_ENV+=	COMPRESS_CMD="${COMPRESS_CMD:S/c//}"
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

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

.include "Makefile.man"

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

.include <bsd.port.post.mk>
