# New ports collection makefile for:    graphviz
# Version required:     1.4
# Date created:         03 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       graphviz_1_4.src.unix
PKGNAME=	graphviz-1.4
CATEGORIES=	graphics tk80
MASTER_SITES=	# http://www.research.att.com/sw/tools/graphviz/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

RESTRICTED=	"Cannot be fetched without license"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
WRKSRC=		${WRKDIR}/gv1.4
MAKEFILE=	makefile
MAN1=		dot.1 dotty.1 lefty.1 neato.1
MANN=		tcldot.n

DOCDIR=		${PREFIX}/share/doc/graphviz

post-install:
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	@${GZIP_CMD} ${DOCDIR}/*.ps

.include <bsd.port.mk>
