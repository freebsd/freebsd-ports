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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmusphinx
DISTNAME=	sphinx2-0.4

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Speech recognition system

DEST=		${WRKSRC}/src/libsphinx2/
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes

# contains i386 sound code
ONLY_FOR_ARCHS=	i386

post-patch:
.for ii in CM_funcs.c hash.c linklist.c list.c salloc.c
	${MV} ${DEST}${ii} ${DEST}${ii}.orig
	${SED} -e "s:<malloc.h>:<stdlib.h>:g" < ${DEST}${ii}.orig > ${DEST}${ii}
.endfor

post-build:
	${ECHO_CMD} "*** WARNING ***"				 > ${PKGMESSAGE}
	${ECHO_CMD} "The sphinx 2 port/package has not had"	>> ${PKGMESSAGE}
	${ECHO_CMD} "proper testing or source review by the"	>> ${PKGMESSAGE}
	${ECHO_CMD} "FreeBSD maintainer."			>> ${PKGMESSAGE}

pre-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
