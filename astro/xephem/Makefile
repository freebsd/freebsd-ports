# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	xephem
PORTVERSION=	3.7.7
CATEGORIES=	astro
MASTER_SITES=	# http://www.clearskyinstitute.com/xephem/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Interactive astronomical ephemeris program

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake jpeg motif
LDFLAGS+=	-lfontconfig
USE_XORG=	xp xt xext xmu x11 xft
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

RESTRICTED=	Personal use only

# XXX needs to be the same as DISTFILES
XEPHEMSRC=	${PORTNAME}-${PORTVERSION}.tar.gz

.include <bsd.port.pre.mk>

.for file in ${XEPHEMSRC}
.if !exists(${DISTDIR}/${file})
IGNORE=	because of licensing restrictions, you must manually fetch ${file}\
	from http://www.clearskyinstitute.com/xephem/,\
	place it in ${DISTDIR} and then run make again
.endif
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC}/../.. -name Makefile -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's|CC = gcc|CC?= ${CC}|g ; \
		s|CFLAGS =|CFLAGS+=|g ; \
		s|LDFLAGS =|LDFLAGS+=|g ; \
		s|-O2 ||g'

pre-build:
	@${ECHO_CMD} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' \
		> ${WRKSRC}/XEphem.ad

pre-install:
	@${FIND} ${WRKSRC}/../.. -name Makefile.bak -type f -delete
	@${CP} ${WRKSRC}/xephem.man ${STAGEDIR}${PREFIX}/man/man1/xephem.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XEphem
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xephem
	@cd ${WRKSRC}; ${COPYTREE_SHARE} \
		"auxil catalogs fifos fits gallery help lo" \
		${STAGEDIR}${PREFIX}/lib/X11/xephem

.include <bsd.port.post.mk>
