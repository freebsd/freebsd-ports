# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	2d1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
DISTNAME=	slib2d1

MAINTAINER=	nakai@FreeBSD.org

RUN_DEPENDS=	guile:${PORTSDIR}/lang/guile

WRKSRC=		${WRKDIR}/slib

USE_ZIP=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/slib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/slib
	${RM} -f ${LOCALBASE}/share/guile/slib
	${LN} -sf ${PREFIX}/share/slib ${LOCALBASE}/share/guile/slib
	${LOCALBASE}/bin/guile -c \
		"(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
