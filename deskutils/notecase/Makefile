# New ports collection makefile for:	notecase
# Date created:				19 July 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	notecase
PORTVERSION=	1.9.3
CATEGORIES=	deskutils textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A hierarchical text notes manager

USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomevfs2 desktopfileutils
USE_GETTEXT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	help.ncd license.txt
INSTALL_TARGET=	install docinstall
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|prefix=/usr|prefix=${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|docsdir=|docsdir=${DOCSDIR}|' \
		${WRKSRC}/Makefile

post-install:
	@-update-mime-database ${PREFIX}/share/mime
	@-update-desktop-database

.include <bsd.port.post.mk>
