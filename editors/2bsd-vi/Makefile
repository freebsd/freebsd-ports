# New ports collection makefile for:	2bsd-vi
# Date created:			2004-07-12
# Whom:				David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	vi
PORTVERSION=	050225
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ex-vi
PKGNAMEPREFIX=	2bsd-
DISTNAME=	ex-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	The original vi editor, updated to run on modern OSes

USE_BZIP2=	yes
USE_REINPLACE=	yes

MAN1=	ex.1 vi.1
MLINKS=	ex.1 edit.1  vi.1 vedit.1  vi.1 view.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/stable-Makefile.patch
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|-DMB||g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
