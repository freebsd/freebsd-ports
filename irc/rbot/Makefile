# New ports collection makefile for:	rbot
# Date created:		14 Apr 2002
# Whom:			David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	rbot
PORTVERSION=	0.9.14
PORTREVISION=	1
CATEGORIES=	irc ruby
MASTER_SITES=	http://ruby-rbot.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Ruby IRC bot similar to infobot

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_PKGNAMEPREFIX}gettext>=1.93.0:${PORTSDIR}/devel/ruby-gettext

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	README REQUIREMENTS ChangeLog

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
