# New ports collection makefile for:   librep
# Version required:    0.7.1
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	librep-0.7.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dcs.warwick.ac.uk/people/John.Harper/librep/

MAINTAINER=	nakai@FreeBSD.org

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-lxpg4"

TAR_VER=	'\"'`${TAR} --version 2>&1 | ${SED} 's/GNU tar version //'`'\"'

post-patch:
		${CAT} ${WRKSRC}/lisp/tar-file-handler.jl | \
		${SED} '/^(defvar tarfh-gnu-tar-version/s/nil/'${TAR_VER}'/' \
		> ${FILESDIR}/tmp.work
		${CP} ${FILESDIR}/tmp.work ${WRKSRC}/lisp/tar-file-handler.jl

.include <bsd.port.mk>
