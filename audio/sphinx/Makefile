# New ports collection makefile for:	sphinx
# Date created:				30 Mar 2000
# Whom:					trevor@jpj.net
#
# $FreeBSD$
#

PORTNAME=	sphinx
PORTVERSION=	2.0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmusphinx
DISTNAME=	sphinx2-0.4

MAINTAINER=	trevor@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes

IGNORE=		"audio read error"

# contains i386 sound code
ONLY_FOR_ARCHS=	i386

post-patch:
	${FIND} ${WRKSRC} -type f -exec ${PERL} -pi -e \
		"s:<malloc.h>:<stdlib.h>:g" {} \;

post-build:
	${ECHO_CMD} "*** WARNING ***"				 > ${PKGMESSAGE}
	${ECHO_CMD} "The sphinx 2 port/package has not had"	>> ${PKGMESSAGE}
	${ECHO_CMD} "proper testing or source review by the"	>> ${PKGMESSAGE}
	${ECHO_CMD} "FreeBSD maintainer."			>> ${PKGMESSAGE}

pre-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
