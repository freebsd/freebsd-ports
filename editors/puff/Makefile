# New ports collection makefile for:   puff
# Date created:        10 April 2003
# Whom:                Leif Pedersen <bilbo@devpit.org>
#
# $FreeBSD$
#

PORTNAME=	puff
PORTVERSION=	0.43
CATEGORIES=	editors
MASTER_SITES=	http://devpit.org/puff/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	Simple and efficient text editor

PLIST_FILES=	bin/puff etc/puff.conf.sample

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -r
	@${REINPLACE_CMD} -e 's|-O[0-9]||g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
