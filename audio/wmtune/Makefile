# New ports collection makefile for:	wmtune
# Version required:			1.0
# Date created:				28 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	wmtune-1.0
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.soren.org/linux/wmtune/dl/ \
		http://www.rostock.zgdv.de/~runge/radio/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		wmtune.diff.gz

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=	yes
USE_X_PREFIX=	yes

PATCH_ARGS	=-p0 -d ${WRKDIR}

post-patch:
	@${GUNZIP_CMD} -c ${DISTDIR}/wmtune.diff.gz | ${PATCH} ${PATCH_ARGS}
	@cd ${WRKSRC}/src; \
		${MV} wmtune.c wmtune.c.orig; \
		${SED} -e 's|/etc|${PREFIX}/etc|' < wmtune.c.orig > wmtune.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtune ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.wmtunerc ${PREFIX}/etc

.include <bsd.port.mk>
