# New ports collection makefile for:	qiv
# Date created:		25 December 1998
# Whom:			Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	qiv
PORTVERSION=	1.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		qiv.1

do-configure:
	@ ${MV} ${WRKSRC}/qiv.1 ${WRKSRC}/qiv.1.pre_sed
	@ ${SED} -e 's#\/usr\/bin#${PREFIX}/bin#g' \
		${WRKSRC}/qiv.1.pre_sed > ${WRKSRC}/qiv.1
	@ ${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	@ ${SED} -e 's#\/usr\/local#${PREFIX}#' \
	         -e 's#RANDOM GETOPT_LONG#RANDOM#' \
	         -e 's#gcc#${CC}#' \
	         -e 's#-O2#${CFLAGS}#' \
	         -e 's#libs-gdk`#libs-gdk` -lgnugetopt#' \
		${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
