# New ports collection makefile for:    graphviz
# Version required:     1.21
# Date created:         03 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/02/21 22:37:58 fenner Exp $
#

DISTNAME=       graphviz_1_21
PKGNAME=	graphviz-1.21
CATEGORIES=	graphics tk42
MASTER_SITES=	# http://www.research.att.com/sw/tools/graphviz/
EXTRACT_SUFX=	.src.unix.tgz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tk42\\.1:${PORTSDIR}/x11-toolkits/tk42

RESTRICTED=	"Can't be fetched without license"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
WRKSRC=		${WRKDIR}/src/src
MAKEFILE=	makefile
MAN1=		dot.1 dotty.1 lefty.1 neato.1 tcldot.1

SELFILEDIR=	${WRKSRC}/cmd/lefty/ws/x11/libfilereq

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/*.ps ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${PREFIX}/share/doc/graphviz
	@${GZIP_CMD} ${PREFIX}/share/doc/graphviz/*.ps

.include <bsd.port.mk>
