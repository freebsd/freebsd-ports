# ports collection makefile for:   mikmod304
# Version required:    3.1.1
# Date created:        16 November 1998
# Whom:                yoshiaki Uchikawa
#
# $Id: Makefile,v 1.8 1998/11/25 01:39:11 flathill Exp $
#

DISTNAME=	mikmod-3.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.multimania.com/miodrag/mikmod/

MAINTAINER=	yoshiaki@kt.rim.or.jp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mikmod.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/mikmod.info*

pre-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
