# New ports collection makefile for:	xzgv
# Date created:				7 Oct 2000
# Whom:					Norio Suzuki <nosuzuki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xzgv
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	nosuzuki@e-mail.ne.jp

USE_GMAKE=	yes
USE_IMLIB=	yes
USE_X_PREFIX=	yes

MAN1=		xzgv.1

post-patch:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/config.mk


.include <bsd.port.mk>
