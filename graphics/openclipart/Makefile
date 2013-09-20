# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports-stable/graphics/openclipart/Makefile,v 1.1 2005/08/09 02:14:05 ahze Exp $

PORTNAME=	openclipart
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.openclipart.org/downloads/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}${SVGPNG}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Open Clip Art Library

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}${SVGPNG}
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

OPTIONS_DEFINE=	PNG
OPTIONS_DEFAULT=	PNG
PNG_DESC=	Install png files

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
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

.include <bsd.port.mk>
