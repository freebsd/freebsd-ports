# New ports collection makefile for:    splay
# Version required:     0.2
# Date created:         Mar 20 1997
# Whom:                 junker@jazz.snu.ac.kr
#
# $Id: Makefile,v 1.1.1.1 1997/03/26 02:10:32 jfitz Exp $
#

DISTNAME=       splay-0.2
CATEGORIES=	audio
MASTER_SITES=   ${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR = apps/sound

MAINTAINER=	junker@jazz.snu.ac.kr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splay ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/randomplay.sh ${PREFIX}/bin

.include <bsd.port.mk>
