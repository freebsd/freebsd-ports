# New ports collection makefile for:    pfe
# Date created:         23 November 1994
# Whom:                 mr
#
# $FreeBSD$
#

PORTNAME=	pfe
PORTVERSION=	0.29.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	OPTIM="${CFLAGS}"
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--disable-float

MAN1=		pfe.1
PLIST_FILES=	bin/pfe lib/pfe/p4ed.so
PLIST_DIRS=	lib/pfe
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "sparc64"
BROKEN=		"Does not compile on !i386 and !sparc64"
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/../doc/pfe.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pfe
	${INSTALL_DATA} ${WRKSRC}/../doc/*.html ${PREFIX}/share/doc/pfe
.endif

.include <bsd.port.post.mk>
