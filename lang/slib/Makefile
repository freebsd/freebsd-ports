# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	2d5
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
DISTNAME=	slib${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org
COMMENT=	A portable scheme library

RUN_DEPENDS=	guile:${PORTSDIR}/lang/guile

WRKSRC=		${WRKDIR}/slib

NO_BUILD=	yes

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DATADIR}
	${MKDIR} ${PREFIX}/share/slib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/slib
	${RM} -f ${LOCALBASE}/share/guile/slib
	${LN} -sf ${PREFIX}/share/slib ${LOCALBASE}/share/guile/slib
	${LOCALBASE}/bin/guile -c \
		"(use-modules (ice-9 slib)) (require 'new-catalog)"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE COPYING ChangeLog FAQ README
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/slib.info ${PREFIX}/info
	install-info ${PREFIX}/info/slib.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
