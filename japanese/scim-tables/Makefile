# New ports collection makefile for:    ja-scim-tables
# Date created:		22 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-tables
PORTVERSION=	0.4.0
CATEGORIES=	japanese
MASTER_SITES=	http://freedesktop.org/~suzhe/sources/

MAINTAINER=	ports@freebsd.org
COMMENT=	SCIM table based Japanese input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`make post-install\'
	@${ECHO}

.include <bsd.port.mk>
