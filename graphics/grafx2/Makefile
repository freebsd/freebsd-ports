# New ports collection makefile for:	grafx2
# Date created:				23 Feb 2009
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grafx2
DISTVERSION=	2.00b98.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	-svn482
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bitmap paint program that supports more than 60 video resolutions

USE_GMAKE=	yes
USE_DOS2UNIX=	yes
USE_SDL=	image ttf
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}
MAKE_ENV+=	DATADIR="${DATADIR}"
CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H \
		-DHAVE_STRUCT_STATFS_F_FSTYPENAME

post-patch:
	@${REINPLACE_CMD} -e 's|macosx|FreeBSD|g' \
		${WRKSRC}/divers.c ${WRKSRC}/mountlist.c ${WRKSRC}/aide.c ${WRKSRC}/init.c

.include <bsd.port.mk>
