# New ports collection makefile for: gdbm
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	1.8.3
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	The GNU database manager

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.if defined(WITH_COMPAT)
INSTALL_TARGET=	install install-compat
PLIST_SUB=	GDBM_COMPAT=""
.else
PLIST_SUB=	GDBM_COMPAT="@comment "
.endif

MAN3=		gdbm.3
INFO=		gdbm

pre-everything::
.if !defined(WITH_COMPAT)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you need UNIX dbm/ndbm compatibility functions,"
	@${ECHO_MSG} "use \"make WITH_COMPAT=yes\""
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
