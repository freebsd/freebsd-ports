# New ports collection makefile for:	xzgv
# Date created:				7 Oct 2000
# Whom:					Norio Suzuki <nosuzuki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xzgv
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	nosuzuki@e-mail.ne.jp

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes

MAN1=		xzgv.1

post-patch:
	@${PERL} -pi -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^PREFIX|#PREFIX|g' ${WRKSRC}/config.mk

.include <bsd.port.mk>
