# New ports collection makefile for:    graphviz
# Version required:     1.21
# Date created:         03 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=       graphviz_1_21
PKGNAME=	graphviz-1.21
CATEGORIES=	graphics
MASTER_SITES=	# http://www.research.att.com/sw/tools/graphviz/
EXTRACT_SUFX=	.src.unix.tgz

MAINTAINER=	ports@FreeBSD.ORG

RESTRICTED=	"Can't be fetched without license"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
WRKSRC=		${WRKDIR}/src/src
MAKEFILE=	makefile
MAN1=		dot.1 dotty.1 lefty.1 neato.1 tcldot.1

SELFILEDIR=	${WRKSRC}/cmd/lefty/ws/x11/libfilereq

post-extract:
	@${MV} ${SELFILEDIR}/dir.c ${SELFILEDIR}/Dir.c
	@${MV} ${SELFILEDIR}/draw.c ${SELFILEDIR}/Draw.c
	@${MV} ${SELFILEDIR}/path.c ${SELFILEDIR}/Path.c
	@${MV} ${SELFILEDIR}/selfile.c ${SELFILEDIR}/SelFile.c
	@${MV} ${SELFILEDIR}/sfinternal.h ${SELFILEDIR}/SFinternal.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/*.ps ${PREFIX}/share/doc/graphviz
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${PREFIX}/share/doc/graphviz
	@${GZIP_CMD} ${PREFIX}/share/doc/graphviz/*.ps

.include <bsd.port.mk>
