# $FreeBSD$

PORTNAME=	charybdis
PORTVERSION=	3.4.2
PORTREVISION=	6
CATEGORIES=	irc net
MASTER_SITES=	http://www.stack.nl/~jilles/irc/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTFILES:M*tbz2}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Powerful IRC daemon, based on ircd-ratbox

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

CONFLICTS=	ircd-ratbox-[0-9]* ircd-ratbox-devel-[0-9]* \
		nefarious-[0-9]* ircd-hybrid-[0-9]* \
		ptlink-ircd-[0-9]* bnc-[0-9]* \
		expect-[0-9]* whois-[0-9]* undernet-ircu-[0-9]* \
		ru-ircd-hybrid-[0-9]* \

MASTER_SITES:=	${MASTER_SITES} \
		${MASTER_SITES:S,$,charybdis-stable-oper-guide/:pdf,}

PORTDOCS=	charybdis-oper-guide.pdf

USES=		libtool pathfix tar:tbz2
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
USERS=		ircd
GROUPS=		ircd
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} \
		--with-rundir=/var/run \
		--enable-fhs-paths \
		--enable-kqueue

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	${PORTDOCS}:pdf

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd \
		${STAGEDIR}${ETCDIR}/ircd.motd.sample

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/charybdis-oper-guide.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
