# New ports collection makefile for:	yafc
# Date created:		10 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yafc
PORTVERSION=	1.1.3
CATEGORIES=	ftp
MASTER_SITES=	https://github.com/downloads/sebastinas/yafc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another ftp client. Similar to ftp(1)

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks4=no --with-socks5=no --with-krb4=no \
		--with-krb5=no --with-gssapi=no

FETCH_ARGS=	-Fpr

MAN1=		yafc.1
INFO=		yafc
PLIST_FILES=	bin/yafc \
		etc/bash_completion.d/yafc
PLIST_DIRSTRY=	etc/bash_completion.d

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.sample ${EXAMPLESDIR}

PLIST_FILES+=	%%EXAMPLESDIR%%/inputrc.sample \
		%%EXAMPLESDIR%%/yafcrc.sample
PLIST_DIRS+=	%%EXAMPLESDIR%%
.endif

.include <bsd.port.mk>
