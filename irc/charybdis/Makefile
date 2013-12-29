# $FreeBSD$

PORTNAME=	charybdis
PORTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	irc net
MASTER_SITES=	http://www.stack.nl/~jilles/irc/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTFILES=	${DISTNAME}.tbz2 ${DOCSDIST}
EXTRACT_ONLY=	${DISTFILES:M*tbz2}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A powerful IRC daemon, based on ircd-ratbox

LICENSE=	GPLv2

CONFLICTS=	ircd-ratbox-[0-9]* ircd-ratbox-devel-[0-9]* \
		nefarious-[0-9]* ircd-hybrid-[0-9]* \
		ptlink-ircd-[0-9]* bnc-[0-9]* \
		expect-[0-9]* whois-[0-9]* undernet-ircu-[0-9]* \
		ru-ircd-hybrid-[0-9]* \

MASTER_SITES:=	${MASTER_SITES} \
		${MASTER_SITES:S,$,charybdis-stable-oper-guide/:pdf,}

PORTDOCS=	charybdis-oper-guide.pdf

USE_AUTOTOOLS=	autoconf
USES=		pathfix
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
USERS=		ircd
GROUPS=		ircd
CONFIGURE_ARGS=	--with-confdir=${ETCDIR} \
		--with-helpdir=${DATADIR}/help \
		--with-logdir=/var/log/${PORTNAME} \
		--with-moduledir=${DATADIR}/modules \
		--enable-kqueue

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIST+=	${PORTDOCS}:pdf
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/charybdis-oper-guide.pdf \
		${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd \
		${STAGEDIR}${ETCDIR}/ircd.motd.sample

.include <bsd.port.mk>
