# New ports collection makefile for:	qiv
# Date created:		25 December 1998
# Whom:			Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	qiv
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.klografx.net/qiv/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Small, fast GDK/Imlib image viewer

USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		qiv.1
PLIST_FILES=	bin/qiv

do-configure:
	@ ${MV} ${WRKSRC}/qiv.1 ${WRKSRC}/qiv.1.pre_sed
	@ ${SED} -e 's#\/usr\/bin#${PREFIX}/bin#g' \
		${WRKSRC}/qiv.1.pre_sed > ${WRKSRC}/qiv.1
	@ ${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	@ ${SED} -e 's#\/usr\/local#${PREFIX}#' \
	         -e 's#gcc#${CC}#' \
	         -e 's#-O2#${CPPFLAGS} ${CFLAGS}#' \
	         -e 's#libs-gdk`#libs-gdk` ${LDFLAGS}#' \
		${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
