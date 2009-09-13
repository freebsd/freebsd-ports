# New ports collection makefile for:	FEAPpv
# Date created:		29 Feb 2006
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	feappv
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	cad science
MASTER_SITES=	http://www.ce.berkeley.edu/~rlt/feappv/
MASTER_SITE_SUBDIR=	feap
DISTFILES=	${PORTNAME}20${EXTRACT_SUFX}
.ifndef NOPORTDOCS
DISTFILES+=	manual.pdf
.endif
DIST_SUBDIR=	feap
EXTRACT_ONLY=	${PORTNAME}20${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite Element Analysis Program "personal version"

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-L

WRKSRC=		${WRKDIR}/ver20
USE_XORG=	x11
USE_FORTRAN=	yes
FFLAGS+=	-O2
MAKEFILE=	makefile
ALL_TARGET=	install

post-patch:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g; s+%%CC%%+${CC}+g;	\
	s+%%FFLAGS%%+${FFLAGS}+g; s+%%CFLAGS%%+${CFLAGS}+g;	\
	s+/usr/X11R6+${LOCALBASE}+g; s+%%WRKSRC%%+${WRKSRC}+;' 	\
	${WRKSRC}/makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/feappv ${PREFIX}/bin/feappv
	@${INSTALL_DATA} ${WRKSRC}/Feappv.a ${PREFIX}/lib/libfeappv.a
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
