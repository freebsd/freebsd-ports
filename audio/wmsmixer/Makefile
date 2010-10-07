# New ports collection makefile for:	wmsmixer
# Date created:				2 April 2001
# Whom:					Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmsmixer
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.dockapps.org/files/63/268/ \
				http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	An audio mixer for the WindowMaker dock

PLIST_FILES=	bin/wmsmixer
PORTDOCS=	README
USE_XORG=	xpm
USE_IMAKE=	YES
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmsmixer ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
