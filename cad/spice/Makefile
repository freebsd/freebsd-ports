# New ports collection makefile for:    spice
# Date created:         26 Mar 96
# Whom:                 Julian Jenkins <kaveman@magna.com.au>
#
# $FreeBSD$
#

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/:sources	\
		ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps/:docs
DISTFILES=	sp3f4.kit${EXTRACT_SUFX}:sources	\
		cp.ps:docs toc.ps:docs doc.ps:docs
DIST_SUBDIR=	spice
EXTRACT_ONLY=	sp3f4.kit${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general-purpose circuit simulation program

USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
MAN1=		sconvert.1 nutmeg.1 spice.1
MAN3=		mfb.3
MAN5=		mfbcap.5
MLINKS=		spice.1 spice3.1
MAKE_ENV+=	STRIP_CMD=${STRIP_CMD}

.ifdef WITHOUT_X11
COMMENT=	A general-purpose circuit simulation program (non-X11 version)
PKGNAMESUFFIX=	-without-x11
MAKE_ARGS+=	-DWITHOUT_X11
.else
USE_XLIB=	yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/ucb|${LOCALBASE}/bin|' ${WRKSRC}/util/build

post-configure:
	@${REINPLACE_CMD} -e 's+@CC@+${CC}+ ; s+@CFLAGS@+${CFLAGS}+ ; \
	    s+@X11BASE@+${X11BASE}+;' \
	    ${WRKSRC}/conf/FreeBSD ${WRKSRC}/conf/FreeBSD.without_x11

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps > ${DOCSDIR}/spice3f3.ps
	${GZIP_CMD} ${DOCSDIR}/*.ps
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
