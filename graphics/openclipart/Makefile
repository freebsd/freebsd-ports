# New ports collection makefile for:	openclipart
# Date created:		2005-07-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/graphics/openclipart/Makefile,v 1.1 2005/08/09 02:14:05 ahze Exp $
#

PORTNAME=	openclipart
PORTVERSION=	0.18
CATEGORIES=	graphics
MASTER_SITES=	http://download.openclipart.org/downloads/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}${SVGPNG}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Open Clip Art Library

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}${SVGPNG}
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

OPTIONS=	PNG "Install png files" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PNG)
SVGPNG=	-full
.else
SVGPNG=	-svgonly
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
		${CPIO} -vpdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.post.mk>
