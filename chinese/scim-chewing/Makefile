# New ports collection makefile for:    zh-scim-chewing
# Date created:		4 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-chewing
PORTVERSION=	0.2.0
CATEGORIES=	chinese
MASTER_SITES=	http://chewing.csie.net/download/scim/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM chewing Chinese input methods

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	chewing.2:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/1.0.0/,/,g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BROKEN=		scim-make-table is not available for 4.x
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}


.include <bsd.port.post.mk>
