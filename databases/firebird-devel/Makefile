# New ports collection makefile for:	Firebird-devel
# Date created:		03 December 2001
# Whom:			Chris Knight <chris@e-easy.com.au>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	2.0.a0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.aims.net.au/chris/firebird/
MASTER_SITE_SUBDIR=firebird
PKGNAMESUFFIX=	-devel
DISTNAME=	firebird2-20031110

MAINTAINER=	chris@e-easy.com.au
COMMENT=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	257
USE_GCC=	3.3

CONFLICTS=	firebird-1.*
NO_PACKAGE=	pkg-install not finished

WRKSRC=		${WRKDIR}/firebird2
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_REINPLACE=	yes

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} "NOTE: If the work directory is on an NFS mount, you will"
	@${ECHO_MSG} "require NFS client locking support for the build to"
	@${ECHO_MSG} "succeed. Currently this is only available on FreeBSD 5.0"
	@${ECHO_MSG} "or greater."
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 1.0.x."
	@${ECHO_MSG} "Cancel this installation now and backup your databases"
	@${ECHO_MSG} "if you have not already done so."
.if !defined(BATCH)
	@sleep 10
.endif

patch-autotools:
	@${DO_NADA}

do-configure:
	@(cd ${WRKSRC} && ${ENV} CC=${CC} CXX=${CXX} MAKE=${GMAKE} ./autogen.sh --prefix=${PREFIX}/firebird --with-lock-manager --with-editline)

do-build:
	@(								\
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE};	\
	cd ${WRKSRC};							\
	${ENV} CC=${CC} CXX=${CXX} ${GMAKE} all;			\
	)

.include <bsd.port.post.mk>
