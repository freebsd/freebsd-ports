# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	1.5.r8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}	\
		http://www.aims.net.au/chris/firebird/
MASTER_SITE_SUBDIR=firebird
DISTNAME=	firebird15-rc8

MAINTAINER=	chris@e-easy.com.au
COMMENT=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
WANT_AUTOCONF_VER=	253
USE_GCC=	3.3

# Don't use ld for linking, use gcc
LD=	gcc

CONFLICTS=	firebird-devel-*

WRKSRC=		${WRKDIR}/firebird15
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

patch-libtool:
	@${DO_NADA}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} MAKE=${GMAKE}	\
	LIBTOOL=libtool13 LIBTOOLIZE=libtoolize13 ./autogen.sh		\
	--prefix=${PREFIX}/firebird --with-lock-manager --with-editline)

do-build:
	@(								\
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE};	\
	cd ${WRKSRC};							\
	${SETENV} CC=${CC} CXX=${CXX} ${GMAKE} all;			\
	)

post-install:
	@(								\
	${INSTALL_DATA} ${FILESDIR}/RELNOTES ${PREFIX}/firebird;	\
	${CAT} ${PKGMESSAGE};						\
	)

.include <bsd.port.post.mk>
