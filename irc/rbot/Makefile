# New ports collection makefile for:	rbot
# Date created:		14 Apr 2002
# Whom:			David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	rbot
PORTVERSION=	0.9.6
CATEGORIES=	irc ruby
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	david+ports@bushong.net

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_SITELIBDIR}/rexml/document.rb:${PORTSDIR}/textproc/ruby-rexml

USE_RUBY=	yes

NO_BUILD=	yes

post-patch:
	@${RUBY} -pi -e 'sub /rbotconf/, "${PREFIX}/etc/rbot"' ${WRKSRC}/rbot.rb

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

.include <bsd.port.mk>
