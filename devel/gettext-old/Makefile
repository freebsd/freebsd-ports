# New ports collection makefile for:   gettext
# Version required:    0.10
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.1.1.1 1998/08/25 16:13:04 kuriyama Exp $
#

DISTNAME=	gettext-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	Nakai@technologist.com

GNU_CONFIGURE=	yes

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

.include <bsd.port.mk>
