# New ports collection makefile for:   librep
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/lang/librep/Makefile,v 1.2 2006/09/10 00:51:12 mezz Exp $

PORTNAME=	librep
PORTVERSION=	0.17.4
CATEGORIES=	lang elisp gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	librep

MAINTAINER=	anray@FreeBSD.org
COMMENT=	An Emacs Lisp like runtime library

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
    		gmp.8:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//} VERSION=${PORTVERSION}

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

INFO=		librep

.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		Does not build on ia64
.endif

.include <bsd.port.post.mk>
