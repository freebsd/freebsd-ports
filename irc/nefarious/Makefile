# New ports collection makefile for:	Nefarious
# Date created:				12 August 2007
# Whom:					Frank J. Laszlo <laszlof@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Nefarious
PORTVERSION=	1.0.1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evilnet

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	IRC server used by evilnet based off of Undernet\'s ircu

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_SUB+=	INSTALL_PREFIX=${INSTALL_PREFIX:S/${PREFIX}\///}
MAN8=		ircd.8

.include <bsd.port.pre.mk>

.if !defined(INSTALL_PREFIX)
INSTALL_PREFIX=${PREFIX}/${PORTNAME}
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

.if defined(WITH_CHROOT)
CONFIGURE_ARGS+=	--with-chroot=${INSTALL_PREFIX}
.endif

.if defined(DOMAIN)
CONFIGURE_ARGS+=	--with-domain=${DOMAIN}
.endif

CONFIGURE_ARGS+=	--prefix=${INSTALL_PREFIX} --mandir=${MANPREFIX}/man --infodir=${PREFIX}/${INFO_PATH}

pre-configure:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "User configurable options for ${PORTNAME}:"
	@${ECHO_CMD} "INSTALL_PREFIX	-	Where to install all Nefarious files (default: PREFIX/Nefarious)"
	@${ECHO_CMD} "WITH_OPENSSL	-	Compile with SSL support"
	@${ECHO_CMD} "WITH_CHROOT	-	chroot the ircd within INSTALL_PREFIX"
	@${ECHO_CMD} "DOMAIN		-	Domain to use for IRCd"
	@${ECHO_CMD} ""
	@sleep 5

.include <bsd.port.post.mk>
