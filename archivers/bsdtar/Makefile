# New ports collection makefile for:	libarchive
# Date created:		11 Jun 2004
# Whom:			Martin Matuska <martin@tradex.sk>
#
# $FreeBSD$

PORTNAME=	bsdtar
PORTVERSION=	2004.06.07
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	martin@tradex.sk
COMMENT=	New tar archiver from FreeBSD-CURRENT

BUILD_DEPENDS=	${LOCALBASE}/lib/libarchive.a:${PORTSDIR}/archivers/libarchive

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include

MAKE_FLAGS+=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/man/man

PLIST_FILES=	bin/bsdtar

USE_REINPLACE=	yes

MANCOMPRESSED=	yes
MAN1=		bsdtar.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502111
IGNORE=		is in the base system
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
