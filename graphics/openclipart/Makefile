# New ports collection makefile for:	openclipart
# Date created:		2005-07-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openclipart
PORTVERSION=	0.15
CATEGORIES=	graphics misc
MASTER_SITES=	http://www.openclipart.org/downloads/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}${SVGPNG}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Open Clip Art Library

USE_BZIP2=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PNG)
SVGPNG=		# empty
.else
SVGPNG=	-svgonly
.endif

pre-everything::
.if !defined(WITHOUT_PNG)
	@${ECHO_MSG} "Disable the install of png files by defining"
	@${ECHO_MSG} "WITHOUT_PNG=yes"
	@${ECHO_MSG} ""
.endif

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${DATADIR}

.include <bsd.port.post.mk>
