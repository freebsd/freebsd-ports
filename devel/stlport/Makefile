# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	4.5.1
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/
DISTNAME=	STLport-${PORTVERSION:S/.b/-b/}

MAINTAINER=	pmarquis@pobox.com

.include <bsd.port.pre.mk>

.if !exists(/usr/include/wchar.h)
BROKEN=		"Requires /usr/include/wchar.h for compilation"
.endif

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}/src
PATCH_WRKSRC=	${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}
USE_GMAKE=	yes
MAKEFILE=	gcc-freebsd.mak
MAKE_ARGS=	INSTALLDIR=${PREFIX}
ALL_TARGET=	clean all
INSTALL_TARGET=	install_unix
INSTALLS_SHLIB=	yes

.if ${OSVERSION} < 440000
BROKEN=		"Not supported on systems prior to FreeBSD 4.4"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/../doc/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.post.mk>
