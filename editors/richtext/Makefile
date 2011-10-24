# New ports collection makefile for:	richtext
# Date created:		2006-07-30
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	richtext
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple RTF editor

BUILD_DEPENDS=	objc:${PORTSDIR}/lang/objc

BROKEN=		does not compile

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xt
USE_MOTIF=	yes

PLIST_FILES=	bin/rt

post-configure:
	${REINPLACE_CMD} -E \
		-e "s,([[:space:]]*EXTRA_LOAD_FLAGS[[:space:]]*=).*,\1," \
		${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rt ${PREFIX}/bin

.include <bsd.port.mk>
