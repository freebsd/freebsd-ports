# New ports collection makefile for:	ja-slrn
# Date created:		6 Sept 1999
# Whom:			Takashi Mega <mega@minz.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.6.2
CATEGORIES=	japanese news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/ \
		http://www.kondara.org/~g/slang/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-doc-j0.9.5.6-0.tar.gz

PATCH_SITES=	${MASTER_SITE_PORTS_JP}
PATCHFILES=	${PORTNAME}-${PORTVERSION}jp0.pat.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	ukatsuta@mud.biglobe.ne.jp

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JDOCSRC=	${WRKDIR}/${PORTNAME}-doc-j0.9.5.6-0
GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
MANLANG=	'' ja
MAN1=		slrn.1

pre-install:
	strip ${WRKSRC}/src/i386objs/slrn
	strip ${WRKSRC}/src/i386objs/slrnpull

post-install:
	${INSTALL_MAN} ${JDOCSRC}/slrn.1 ${PREFIX}/man/ja/man1
	${CP} -r ${JDOCSRC} ${PREFIX}/share/doc/slrn/ja

.include <bsd.port.mk>
