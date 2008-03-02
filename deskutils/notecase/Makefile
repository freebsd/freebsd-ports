# New ports collection makefile for:	notecase
# Date created:				19 July 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	notecase
PORTVERSION=	1.5.8
CATEGORIES=	deskutils textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hierarchical text notes manager

USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomevfs2 desktopfileutils
USE_GETTEXT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install docinstall
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|prefix=/usr|prefix=${PREFIX}|' \
		${WRKSRC}/Makefile

post-install:
	@-update-mime-database ${PREFIX}/share/mime
	@-update-desktop-database

.include <bsd.port.post.mk>
