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
		http://www.rostock.zgdv.de/~runge/radio/ \
		http://www.fxp.org/~jedgar/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${WMTUNE_DIFF}

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
USE_GMAKE=	yes
USE_X_PREFIX=	yes

PATCH_ARGS	=-p0 -d ${WRKDIR}

.include <bsd.port.pre.mk>

.if !defined(USE_RADIOTRACK)
WMTUNE_DIFF=	wmtune.diff.gz
pre-patch:
	@${ECHO}
	@${ECHO} "To enable support for RadioTrack radio cards,"
	@${ECHO} "define USE_RADIOTRACK (make USE_RADIOTRACK=yes)."
	@${ECHO}
	@sleep 3
.else
WMTUNE_DIFF=	wmtune.radiotrack.diff.gz
.endif

post-patch:
	@${GUNZIP_CMD} -c ${DISTDIR}/${WMTUNE_DIFF} | ${PATCH} ${PATCH_ARGS}
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	@${SED} -e 's|-O2|${CFLAGS}|' -e 's|cc|${CC}|' \
		< ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

do-configure:
	@${PERL} -pi.orig -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/src/wmtune.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtune ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.wmtunerc ${PREFIX}/etc

.include <bsd.port.post.mk>
