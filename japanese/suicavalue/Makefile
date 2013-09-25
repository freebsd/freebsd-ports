# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	suicavalue
PORTVERSION=	2007.05.15
CATEGORIES=	japanese
MASTER_SITES=	http://www.imfj.net/people/nomura/soft/PaSoRi/
DISTNAME=	SuicaValue
EXTRACT_SUFX=	.c
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	Utility to print a statement of Suica

LIB_DEPENDS=	pasori.1:${PORTSDIR}/devel/libpasori

PLIST_FILES=	bin/SuicaValue

post-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
