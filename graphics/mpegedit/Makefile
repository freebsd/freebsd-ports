# New ports collection makefile for:	mpegedit
# Date created:		Thu Aug  1 10:50:57 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mpegedit
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.netsw.org/netsw/Graphic/Movie/MPEG/mpegedit/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	pnm.1:${PORTSDIR}/graphics/netpbm

USE_X_PREFIX=	yes

post-extract:
	@find ${WRKSRC} -name '.depend' | xargs ${RM} -f

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_edit ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mpeg_edit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mpeg_edit
	${INSTALL_DATA} ${WRKSRC}/manual.ps ${PREFIX}/share/doc/mpeg_edit
.endif

.include <bsd.port.mk>
