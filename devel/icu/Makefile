# New ports collection makefile for:	icu
# Date created:				22 Jan 2001
# Whom:					dwm
#
# $FreeBSD$
#

PORTNAME=	icu
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://oss.software.ibm.com/developerworks/opensource/icu/project/download/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	International Components for Unicode (from IBM)(old version)

WRKSRC=		${WRKDIR}/${PORTNAME}/source
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=--disable-shared --enable-static
CONFIGURE_ENV=	CXXFLAGS="-O3"
CONFIGURE_ENV+=	CFLAGS="-O3"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "ia64" || ${MACHINE_ARCH} == "sparc64"
IGNORE=		"does not build on this architecture, use devel/icu2 instead"
.endif

.include <bsd.port.post.mk>
