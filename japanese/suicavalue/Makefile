# New ports collection makefile for:	suicavalue
# Date created:				18 January 2007
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$

PORTNAME=	suicavalue
PORTVERSION=	2007.01.06
CATEGORIES=	japanese
MASTER_SITES=	http://www.imfj.net/people/nomura/soft/PaSoRi/
DISTNAME=	SuicaValue
EXTRACT_SUFX=	.c
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Utility to print a statement of Suica

BUILD_DEPENDS=	${LOCALBASE}/lib/libpasori.a:${PORTSDIR}/devel/libpasori

PLIST_FILES=	bin/SuicaValue

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
