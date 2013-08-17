# Created by: David Bushong <david+ports@bushong.net>
# $FreeBSD$

PORTNAME=	rbot
PORTVERSION=	0.9.15
PORTREVISION=	1
CATEGORIES=	irc ruby
MASTER_SITES=	http://ruby-rbot.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Ruby IRC bot similar to infobot

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		rubygem-gettext>=1.93.0:${PORTSDIR}/devel/rubygem-gettext

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	REQUIREMENTS ChangeLog

.include <bsd.port.pre.mk>

pre-install:
	${RM} ${WRKSRC}/bin/svnwatch-postcommit-hook

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
