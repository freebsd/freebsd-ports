# New ports collection makefile for:	rbot
# Date created:		14 Apr 2002
# Whom:			David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	rbot
PORTVERSION=	0.9.2
CATEGORIES=	irc ruby
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	david+ports@bushong.net

USE_RUBY=	yes

NO_BUILD=	yes

post-patch:
	@${RUBY} -pi -e 'sub /rbotconf/, "${PREFIX}/etc/rbot"' ${WRKSRC}/rbot.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbot.rb ${PREFIX}/bin/rbot
	${MKDIR} ${RUBY_SITELIBDIR}/rbot
	${INSTALL_DATA} ${WRKSRC}/rbot/*.rb ${RUBY_SITELIBDIR}/rbot
	${MKDIR} ${RUBY_SITELIBDIR}/rbot/languages
	${INSTALL_DATA} ${WRKSRC}/rbot/languages/* \
		${RUBY_SITELIBDIR}/rbot/languages
	${MKDIR} ${RUBY_SITELIBDIR}/rbot/plugins
	${INSTALL_DATA} ${WRKSRC}/rbot/plugins/* \
		${RUBY_SITELIBDIR}/rbot/plugins
	${MKDIR} ${RUBY_SITELIBDIR}/rbot/dbplugins
	${INSTALL_DATA} ${WRKSRC}/rbot/dbplugins/* \
		${RUBY_SITELIBDIR}/rbot/dbplugins
	${MKDIR} ${PREFIX}/etc/rbot
	${INSTALL_DATA} ${WRKSRC}/rbotconf/*.rbot ${PREFIX}/etc/rbot
	${MKDIR} ${PREFIX}/etc/rbot/keywords
	${MKDIR} ${PREFIX}/etc/rbot/logs
	${MKDIR} ${PREFIX}/etc/rbot/quotes
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/rbot
	( cd ${WRKSRC}/doc && ${TAR} -cpf - * ) | \
		${TAR} -C ${RUBY_DOCDIR}/rbot -xpf -
.endif

.include <bsd.port.mk>
