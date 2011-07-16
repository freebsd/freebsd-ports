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

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/pxz
MAN1=	pxz.1

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/CC=.*/CC:=$${CC}/g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
