# New ports collection makefile for:	yafc
# Date created:		10 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yafc
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Yet another ftp client. Similar to ftp(1)

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-socks4=no --with-socks5=no --with-krb4=no \
		--with-krb5=no --with-gssapi=no

MAN1=		yafc.1
INFO=		yafc
PLIST_FILES=	bin/yafc \
		%%EXAMPLESDIR%%/inputrc.sample \
		%%EXAMPLESDIR%%/yafcrc.sample
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
