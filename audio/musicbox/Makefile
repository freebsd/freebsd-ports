# New ports collection makefile for:	musicbox
# Date created:        			2000-12-31
# Whom:					trevor
# based on the NetBSD pkgsrc by tron@NetBSD.org
#
# $NetBSD: Makefile,v 1.7 2000/07/14 16:04:19 agc Exp $
# $FreeBSD$
#

PORTNAME=	musicbox
PORTVERSION=	1.01p2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_NETBSD} # ftp://freebsd.csie.nctu.edu.tw/Upload/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	X11 front-end for mpg123

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_GCC=	2.95
USE_QT_VER=	1
DOCS=		ChangeLog README
EVAL_PREFIX+=	QT1DIR=qt1
PATH=		${QT1DIR}/qt/bin:$$PATH
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/musicbox-1.01

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501013
BROKEN=		"compilation error"
.endif

pre-install:
	${ECHO_CMD} bin/musicbox > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} share/doc/musicbox/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/musicbox >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/musicbox
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/musicbox
.endfor
.endif

.include <bsd.port.post.mk>
