# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Modular FTP server configurable online using SITE commands

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

DOCS=		AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst \
		src/CHANGELOG src/DOCS_XFERLOG_FORMAT src/KNOWN_BUGS src/TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
