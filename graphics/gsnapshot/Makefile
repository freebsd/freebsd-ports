# New ports collection makefile for:	gsnapshot
# Date created:		23 July 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gsnapshot
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/gould/${PORTNAME}/release%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gtk+ based screen capture

USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
USE_GNOME=	gtk20 libwnck libxml2
USE_XORG=	x11 xmu
USE_PKGCONFIG=	yes

CFLAGS+=	-fPIC -I${LOCALBASE}/include/libxml2

PORTDOCS=	AUTHORS COPYING INSTALL README TODO

DESKTOP_ENTRIES=	"gsnapshot" \
			"A gtk+ based screen capture" \
			"" \
			"gsnapshot" \
			"Application;Graphics;" \
			"false"

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}
	@${LN} -sf ${AUTOMAKE_DIR}/depcomp ${WRKSRC}
	@${LN} -sf ${AUTOMAKE_DIR}/missing ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
