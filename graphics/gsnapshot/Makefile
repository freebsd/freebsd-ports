# New ports collection makefile for:	gsnapshot
# Date created:		23 July 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gsnapshot
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gould

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gtk+ based screen capture

USE_AUTOTOOLS=	automake:15:env libtool:22
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

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
