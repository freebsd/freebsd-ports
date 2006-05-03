# New ports collection makefile for:	Z88
# Date created:		Dec. 2004
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	z88
PORTVERSION=	11.0
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.uni-bayreuth.de/pub/uni-bayreuth/LS-CAD/unix/:srcs \
		ftp://ftp.uni-bayreuth.de/pub/uni-bayreuth/LS-CAD/manual/:dcs
DISTFILES=	${PORTNAME}src${EXTRACT_SUFX}:srcs ${PORTNAME}mane.pdf:dcs
DIST_SUBDIR=	z88
EXTRACT_ONLY=	${PORTNAME}src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A compact Finite Element Analysis System

NO_WRKSUBDIR=	yes
USE_GL=		yes
USE_MOTIF=	yes

#These defaults can be changed in z88.fcd too
BROWSER?=	mozilla
XEDITOR?=	nedit

Z88_BINS=	z88f z88i1 z88i2 z88com z88d z88e z88g z88h z88n z88o	\
		z88p z88v  z88x laserj88 pxon88
Z88_DATA=	z88.fcd z88.dyn *.dxf *.txt

post-patch:
	@${CP} ${WRKSRC}/z88.fcd.linux ${WRKSRC}/z88.fcd
	@${CP} ${WRKSRC}/z88.mk.kernel.linux ${WRKSRC}/z88kernel.mk
	@${CP} ${WRKSRC}/z88.mk.other.linux ${WRKSRC}/z88other.mk
	@${CP} ${FILESDIR}/z88.sh ${WRKSRC}/z88.sh
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+mozilla+${BROWSER}+ ; \
	s+nedit+${XEDITOR}+ ;' \
		${WRKSRC}/z88.fcd
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ; s+%%CFLAGS%%+${CFLAGS}+g' \
		${WRKSRC}/z88kernel.mk
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ; s+%%CFLAGS%%+${CFLAGS}+g ; \
	s+%%X11BASE%%+${X11BASE}+g;' \
		${WRKSRC}/z88other.mk
	@${REINPLACE_CMD} -e 's+%%PREFIX%%+${PREFIX}+g; ' \
		${WRKSRC}/z88.sh

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f z88kernel.mk kernel)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f z88other.mk other clean)

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/z88.sh ${PREFIX}/bin/z88
	@${INSTALL_PROGRAM} ${Z88_BINS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${Z88_DATA:S|^|${WRKSRC}/|} ${DATADIR}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.htm ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.gif ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.jpg ${DOCSDIR}
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/z88mane.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
