# New ports collection makefile for:    zh-scim-tables
# Date created:		22 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-tables
PORTVERSION=	0.4.1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freedesktop.org/~suzhe/sources/
MASTER_SITE_SUBDIR=scim

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	SCIM table based Chinese input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BROKEN=		scim-make-table is not available for 4.x
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`make post-install\'
	@${ECHO}

.include <bsd.port.post.mk>
