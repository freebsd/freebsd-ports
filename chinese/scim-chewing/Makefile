# New ports collection makefile for:    zh-scim-chewing
# Date created:		4 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-chewing
PORTVERSION=	0.0.1
CATEGORIES=	chinese
MASTER_SITES=	http://jserv.sayya.org/qooing/
DISTNAME=	${PORTNAME}-20041130

MAINTAINER=	ports@FreeBSD.Org
COMMENT=	SCIM chewing Chinese input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	chewing:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15

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
