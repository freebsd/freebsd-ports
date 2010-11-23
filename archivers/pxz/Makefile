# New ports collection makefile for:	pxz
# Date created:		2011-23-16
# Whom:			mm
#
# $FreeBSD$
#

PORTNAME=	pxz
PORTVERSION=	0.20101123
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm
DISTNAME=	pxz-git-${PORTVERSION:S/0.//}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Parallel LZMA compressor using liblzma

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/pxz
MAN1=	pxz.1

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man

.if !defined(NOPORTDOCS)
PORTDOCS=	COPYING
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/CC=.*/CC:=$${CC}/g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif

.include <bsd.port.post.mk>
