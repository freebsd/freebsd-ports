# New ports collection makefile for:	edyvalue
# Date created:				18 January 2007
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$

PORTNAME=	edyvalue
PORTVERSION=	2007.01.06
CATEGORIES=	japanese
MASTER_SITES=	http://www.imfj.net/people/nomura/soft/PaSoRi/
DISTNAME=	EdyValue
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.c
EXTRACT_ONLY=

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Utility to print a statement of Edy card

BUILD_DEPENDS=	${LOCALBASE}/lib/libpasori.a:${PORTSDIR}/devel/libpasori

PLIST_FILES=	bin/EdyValue

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
