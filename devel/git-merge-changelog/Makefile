# New ports collection makefile for:	git-merge-changelog
# Date created:		19 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	git-merge-changelog
PORTVERSION=	${GNULIB_PORTVERSION}
PORTREVISION=	${GNULIB_PORTREVISION}
PORTEPOCH=	${GNULIB_PORTEPOCH}
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Git "merge" driver for GNU style ChangeLog files

EXTRACT_DEPENDS=	${GNULIB_DIR}/lib/${PORTNAME}.c:${GNULIB_PORTDIR}	\
			automake-1.12:${PORTSDIR}/devel/automake		\
			autoconf-2.69:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

GNULIB_DIR=	${LOCALBASE}/share/gnulib
GNULIB_PORT=	devel/gnulib
GNULIB_PORTDIR=	${PORTSDIR}/${GNULIB_PORT}
GNULIB_PORTVERSION!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTVERSION
GNULIB_PORTREVISION!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTREVISION
GNULIB_PORTEPOCH!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTEPOCH

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${GNULIB_DIR}; ./gnulib-tool --create-testdir --dir="${WRKSRC}" ${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
