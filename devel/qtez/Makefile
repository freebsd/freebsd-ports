# New ports collection makefile for:	qtez
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	qtez
PORTVERSION=	0.77a
CATEGORIES=	devel
MASTER_SITES=	http://qtez.zax.net/qtez-extras/
DISTNAME=	QtEZ.current-src

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_QT=		yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/qtez_src
CFLAGS+=	-pedantic

BROKEN=		"Compiler error"

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/qtez_src/bin/qtez ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/qtez
	@cd ${WRKDIR}/qtez_src/demo; tar cf - . | (cd ${PREFIX}/share/examples/qtez; tar xf - )

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/qtez
.for file in INSTALL KDE.README README TODO
	@${INSTALL_DATA} ${WRKDIR}/qtez_src/${file} ${PREFIX}/share/doc/qtez
.endfor
	@cd ${WRKDIR}/qtez_src/docs; tar cf - . | (cd ${PREFIX}/share/doc/qtez; tar xf - )
.endif

.include <bsd.port.mk>
