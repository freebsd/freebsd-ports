# New ports collection makefile for:	manedit
# Date created:				9 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	manedit
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://wolfpack.twu.net/users/wolfpack/ \
		http://distro.ibiblio.org/pub/linux/distributions/amigolinux/download/Applications/Editors/manedit-0.8.1/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A UNIX manual page editor and viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FreeBSD

MAN1=		manedit.1

pre-configure:
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -E 's,(viewerfio.c),\1 mntent_compat.c,; \
			      s,(viewerfio.h),\1 mntent.h,' \
		${WRKSRC}/Makefile.srclist

.include <bsd.port.mk>
