# New ports collection makefile for:	star-devel
# Date created:				19.06.2004 22:27:00 CEST
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	star
DISTVERSION=	1.5a84
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/alpha/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Unique standard tape archiver with many enhancements

BUILD_DEPENDS=	${LOCALBASE}/bin/smake:${PORTSDIR}/devel/smake

CONFLICTS=	star-1.4*
LATEST_LINK=	star-devel

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USE_BZIP2=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		star.1
MAN5=		star.5
MLINKS=		star.1 ustar.1 star.5 ustar.5
.else
XMKFLAGS=	XMK_FILE=""
.endif

MAKE_ENV+=	MAKEFLAGS=${MAKEFLAGS}

PORTDOCS=	README README.crash README.mtio README.pattern STARvsGNUTAR \
		README.ACL README.largefiles README.otherbugs \
		README.posix-2001

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/smake
	@cd ${WRKSRC}/star && ${MAKE_ENV} ${LOCALBASE}/bin/smake -f Makefile.doc

do-install:
	@cd ${WRKSRC}/star && ${MAKE_ENV} ${LOCALBASE}/bin/smake \
		${INSTALL_TARGET} INS_BASE=${PREFIX} ${XMKFLAGS}
	@${STRIP_CMD} ${PREFIX}/bin/star

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/star/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
