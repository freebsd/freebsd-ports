# New ports collection makefile for: japanese AFM files
# Date created:		11 September 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	japaneseAFM
PORTVERSION=	1.0
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese AFM fonts

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

AFMDIR=		${PREFIX}/share/fonts/afm

do-install:
	@${MKDIR} ${AFMDIR}
.for font in GothicBBB-Medium Ryumin-Light
.for dir in H V
	${INSTALL_DATA} ${WRKSRC}/${font}-${dir} ${AFMDIR}
.endfor
.endfor

.include <bsd.port.mk>
