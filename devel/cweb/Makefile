# New ports collection makefile for:	cweb
# Date created:		10 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cweb
PORTVERSION=	3.63
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	web/c_cpp/cweb

MAINTAINER=	tg@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		cweb.1

pre-install:
	@${MKDIR} ${PREFIX}/share/cweb
	@${MKDIR} ${PREFIX}/share/texmf/tex/generic/misc

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cweb
	@${INSTALL_DATA} ${WRKDIR}/cwebman.tex ${PREFIX}/share/doc/cweb
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
