# New ports collection makefile for:	ja-slrn
# Version required:	0.9.5.4
# Date created:		26 Jun 1998
# Whom:			Takashi Mega <mega@minz.org>
#
# $FreeBSD$
#

DISTNAME=	slrn0.9.5.4
PKGNAME=	ja-slrn-0.9.5.4
CATEGORIES=	japanese news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/ \
		http://home.sprintmail.com/~kikutani/slang/
DISTFILES= 	slrn0.9.5.4.tar.gz  slrn-doc-j0.9.5.3-0.tar.gz

PATCH_SITES=	http://home.sprintmail.com/~kikutani/slang/
PATCHFILES= 	slrn0.9.5.4jp0.pat.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mega@minz.org

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang

WRKSRC=         ${WRKDIR}/slrn
JDOCSRC=	${WRKDIR}/slrn-doc-j0.9.5.3-0
HAS_CONFIGURE=	yes
ALL_TARGET=     all slrnpull
MANLANG=	ja ''
MAN1=		slrn.1

do-build:
	@(cd ${WRKSRC}/src; make ${ALL_TARGET})

do-install:
	${ECHO} "installing slrn and slrnpull in ${PREFIX}/bin"
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/slrnpull ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/chkslang ${PREFIX}/bin
	${ECHO} "installing documents files in ${PREFIX}/share/doc/slrn"
	${CP} -r ${WRKSRC}/doc ${PREFIX}/share/doc/slrn
	${CP} -r ${WRKSRC}/slrnpull ${PREFIX}/share/doc/slrnpull
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${JDOCSRC}/slrn.1 ${PREFIX}/man/ja/man1
	${CP} -r ${JDOCSRC} ${PREFIX}/share/doc/slrn/ja

.include <bsd.port.mk>
