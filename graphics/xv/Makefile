# New ports collection makefile for:	xv
# Version required:	3.10a
# Date created:		30 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.18 1998/04/23 21:06:28 vanilla Exp $
#

DISTNAME=	xv-3.10a
CATEGORIES=     graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.kuis.kyoto-u.ac.jp/X11/contrib/clients/xv/ \
		ftp://ftp.tohoku.ac.jp/pub/X/app/xv/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-magpic2-PhotoCD-patch.tar.gz # only from Japan

PATCH_SITES=    ftp://ftp.cis.upenn.edu/pub/xv/
PATCHFILES=     xv-3.10a.JPEG-patch xv-3.10a.TIFF-patch

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=    jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1:${PORTSDIR}/graphics/tiff34 \
		png\\.2\\.:${PORTSDIR}/graphics/png

USE_IMAKE=	yes

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/Patch.magpic2.PhotoCD.XV310a

post-install:
	${MKDIR} ${PREFIX}/share/doc/xv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
.endif

.include <bsd.port.mk>
