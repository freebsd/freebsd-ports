# New ports collection makefile for:	nvi-devel
# Date created:			6 July 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.81.4
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dd@FreeBSD.org

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/iconv
LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
PATCH_WRKSRC=		${WRKDIR}
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS+=	--with-db3=${PREFIX}
CONFIGURE_SCRIPT=	../dist/configure

.include <bsd.port.pre.mk>

# We need src/include/wchar.h and friends.  This isn't the exact
# version we need, but it's close enough.
.if ${OSVERSION} < 500019
BROKEN=		"need wide character support"
.endif

post-install:
	${MV} ${PREFIX}/bin/vi ${PREFIX}/bin/nvi-devel

.include <bsd.port.post.mk>
