# New ports collection makefile for:	hsftp
# Date created:				Mon 03 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	hsftp
PORTVERSION=	1.13
CATEGORIES=	ftp
MASTER_SITES=	http://la-samhna.de/hsftp/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP emulator that uses ssh to transport commands/data

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline
MAKEFILE=	makefile
MAN1=		hsftp.1
PLIST_FILES=	bin/hsftp

.if defined(WITH_OPENSSH)
RUN_DEPENDS=	ssh:${PORTSDIR}/security/openssh
CONFIGURE_ARGS+=	--with-openssh
.endif

pre-everything::
.if !defined(WITH_OPENSSH)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you would like build hsftp with OpenSSH support"
	@${ECHO_MSG} "you must set the variable WITH_OPENSSH"
	@${ECHO_MSG}
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "Building hsftp with OpenSSH support"
	@${ECHO_MSG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hsftp.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
