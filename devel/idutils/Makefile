# New ports collection makefile for:	id-utils
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	id-utils
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	idutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	coreutils-[0-9]* linux-gid-[0-9]* sh-utils-[0-9]*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

INFO=		id-utils

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${RM} -f ${WRKSRC}/lib/getopt.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/id-utils.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
