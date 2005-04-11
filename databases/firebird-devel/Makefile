# New ports collection makefile for:	Firebird-devel
# Date created:		03 December 2001
# Whom:			Chris Knight <chris@e-easy.com.au>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	2.0.a1
CATEGORIES=	databases
MASTER_SITES=	http://www.ramenzoni.com.br/~garga/firebird/
MASTER_SITE_SUBDIR=	firebird
PKGNAMESUFFIX=	-devel
DISTNAME=	firebird2-20050327

MAINTAINER=	freebsd@galle.com.br
COMMENT=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

USE_BZIP2=		yes
USE_GMAKE=		yes
WANT_LIBTOOL_VER=	15
WANT_AUTOCONF_VER=	259
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS=		--with-lock-manager --with-editline
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GCC=		3.4

PREFIX?=	${LOCALBASE}/${PORTNAME}
NO_MTREE=	yes

CONFLICTS=	firebird-1.*
NO_PACKAGE=	pkg-install not finished

WRKSRC=		${WRKDIR}/firebird2
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not build on FreeBSD-4.x"
.endif

pre-everything::
	@${ECHO_MSG} "NOTE: If the work directory is on an NFS mount, you will"
	@${ECHO_MSG} "require NFS client locking support for the build to"
	@${ECHO_MSG} "succeed."
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 1.0.x."
	@${ECHO_MSG} "Cancel this installation now and backup your databases"
	@${ECHO_MSG} "if you have not already done so."
.if !defined(BATCH)
	@sleep 10
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
