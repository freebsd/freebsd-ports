# New ports collection makefile for:	rbot
# Date created:		14 Apr 2002
# Whom:			David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	rbot
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	irc ruby
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	david+ports@bushong.net
COMMENT=	Ruby IRC bot similar to infobot

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml

NO_BUILD=	yes

post-patch:
	@${RUBY} -pi -e 'sub /rbotconf/, "${PREFIX}/etc/rbot"' ${WRKSRC}/rbot.rb
	@rm ${WRKSRC}/rbot/*.orig
	@rm ${WRKSRC}/rbot/plugins/*.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbot.rb ${PREFIX}/bin/rbot
	${TAR} -C ${WRKSRC} -cf - rbot | ${TAR} -C ${RUBY_SITELIBDIR} -xkpf -
	${MKDIR} ${PREFIX}/etc/rbot
	( cd ${WRKSRC}/rbotconf && ${TAR} -cf - * ) | \
		${TAR} -C ${PREFIX}/etc/rbot -xkpf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	( cd ${WRKSRC}/doc && ${TAR} -cf - * ) | \
		${TAR} -C ${RUBY_MODDOCDIR} -xpf -
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
