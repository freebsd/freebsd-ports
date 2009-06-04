# New ports collection makefile for:   clips
# Date created:        8 July 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	clips
PORTVERSION=	6.24
CATEGORIES=	lang
MASTER_SITES=	http://www.ghg.net/clips/download/source/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}
DISTFILES=	clipssrc.tar.Z ${MAKEFILE}
DIST_SUBDIR=	clips-${PORTVERSION}
EXTRACT_ONLY=	${DISTFILES:M*.tar.*}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A productive development and delivery expert system tool

WRKSRC=		${WRKDIR}/${PORTNAME}src/${PORTNAME}src

MAKEFILE=	makefile.gcc
ALL_TARGET=	clips

PLIST_FILES=	bin/clips

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${MAKEFILE} ${WRKSRC}/

do-patch:
	${REINPLACE_CMD} -e 's#gcc #${CC} ${CFLAGS} #g' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clips ${PREFIX}/bin/

.include <bsd.port.mk>
