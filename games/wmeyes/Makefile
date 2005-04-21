# New ports collection makefile for: wmeyes
# Date created:        18 March 1999
# Whom:                Zenin <zenin@archive.rhps.org>
#
# $FreeBSD$
#

PORTNAME=	wmeyes
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://www.bstern.org/wmeyes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The world's most useless WindowMaker dock app

USE_IMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
NO_INSTALL_MANPAGES=	yes

PORTDOCS=	README
PLIST_FILES=	bin/wmeyes

post-patch:
	@${REINPLACE_CMD} -e 's|Target(|TargetNoMan(|g' ${WRKSRC}/Imakefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
