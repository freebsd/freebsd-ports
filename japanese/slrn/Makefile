# New ports collection makefile for:	ja-slrn
# Version required:	0.9.5.7
# Date created:		6 Sept 1999
# Whom:			Takashi Mega <mega@minz.org>
#
# $FreeBSD$
#

DISTNAME=	slrn-0.9.5.7
PKGNAME=	ja-slrn-0.9.5.7
CATEGORIES=	japanese news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/ \
		http://home.sprintmail.com/~kikutani/slang/
DISTFILES= 	slrn-0.9.5.7.tar.gz  slrn-doc-j0.9.5.6-0.tar.gz

PATCH_SITES=	http://home.sprintmail.com/~kikutani/slang/
PATCHFILES= 	slrn0.9.5.7jp0.pat.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mega@minz.org

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang

WRKSRC=         ${WRKDIR}/slrn-0.9.5.7
JDOCSRC=	${WRKDIR}/slrn-doc-j0.9.5.6-0
GNU_CONFIGURE=	yes
ALL_TARGET=     all slrnpull
MANLANG=	'' ja
MAN1=		slrn.1

pre-install:
	strip ${WRKSRC}/src/i386objs/slrn
	strip ${WRKSRC}/src/i386objs/slrnpull

post-install:
	${INSTALL_MAN} ${JDOCSRC}/slrn.1 ${PREFIX}/man/ja/man1
	${CP} -r ${JDOCSRC} ${PREFIX}/share/doc/slrn/ja

.include <bsd.port.mk>
