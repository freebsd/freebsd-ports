# New ports collection makefile for:	sphinx
# Date created:				30 Mar 2000
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	sphinx
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmu${PORTNAME}/${PORTNAME}2/0.4
DISTNAME=	sphinx2-0.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

DEST=		${WRKSRC}/src/libsphinx2/
USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes
USE_AUTOTOOLS=libtool:22

# contains i386 sound code
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's:<malloc.h>:<stdlib.h>:g' \
		${WRKSRC}/src/libsphinx2/CM_funcs.c	\
		${WRKSRC}/src/libsphinx2/hash.c	\
		${WRKSRC}/src/libsphinx2/list.c	\
		${WRKSRC}/src/libsphinx2/salloc.c
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

post-build:
	${ECHO_CMD} "*** WARNING ***"				 > ${PKGMESSAGE}
	${ECHO_CMD} "The sphinx 2 port/package has not had"	>> ${PKGMESSAGE}
	${ECHO_CMD} "proper testing or source review by the"	>> ${PKGMESSAGE}
	${ECHO_CMD} "FreeBSD maintainer."			>> ${PKGMESSAGE}

pre-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
