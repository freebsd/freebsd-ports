# New ports collection makefile for:	wmtune
# Date created:				28 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	wmtune
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.fxp.org/~jedgar/distfiles/:diff \
		http://www.rostock.igd.fhg.de/private/runge/radio/:wmtune \
		http://www.soren.org/linux/wmtune/dl/:wmtune
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:wmtune \
		${WMTUNE_DIFF}:diff
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Dockable radio program for the BT848/878 and RadioTrack cards

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes

PATCH_ARGS	=-p0 -d ${WRKDIR}

.include <bsd.port.pre.mk>

.if !defined(WITH_RADIOTRACK)
WMTUNE_DIFF=	wmtune.diff.gz
pre-fetch:
	@${ECHO}
	@${ECHO} "To enable support for RadioTrack radio cards,"
	@${ECHO} "define WITH_RADIOTRACK (make WITH_RADIOTRACK=yes)."
	@${ECHO}
	@sleep 3
.else
WMTUNE_DIFF=	wmtune.radiotrack.diff.gz
.endif

post-patch:
	@${GUNZIP_CMD} -c ${DISTDIR}/${WMTUNE_DIFF} | ${PATCH} ${PATCH_ARGS}
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' -e 's|cc|${CC}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/wmtune.c

do-configure:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/src/wmtune.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtune ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.wmtunerc ${PREFIX}/etc

.include <bsd.port.post.mk>
