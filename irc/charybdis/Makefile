# New ports collection Makefile for:	charybdis
# Date created:	 	6th March 2011
# Whom:			Chris Rees <utisoft@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	charybdis
PORTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	irc net
MASTER_SITES=	http://www.stack.nl/~jilles/irc/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTFILES=	${DISTNAME}.tbz2
EXTRACT_ONLY=	${DISTFILES:M*tbz2}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A powerful IRC daemon, based on ircd-ratbox

LICENSE=	GPLv2

CONFLICTS=	ircd-ratbox-[0-9]* ircd-ratbox-devel-[0-9]* \
		nefarious-[0-9]* ircd-hybrid-[0-9]* \
		ptlink-ircd-[0-9]* bnc-[0-9]* \
		expect-[0-9]* whois-[0-9]* undernet-ircu-[0-9]* \
		ru-ircd-hybrid-[0-9]* \

MAN8=		ircd.8
PORTDOCS=	*

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${ETCDIR} \
		--with-helpdir=${DATADIR}/help \
		--with-logdir=/var/log/${PORTNAME} \
		--with-moduledir=${DATADIR}/modules \
		--enable-kqueue

USERS=	ircd
GROUPS=	ircd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	charybdis-oper-guide.pdf:pdf
MASTER_SITES+=	http://www.stack.nl/~jilles/irc/charybdis-stable-oper-guide/:pdf
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's#(libdir)/pkgconfig#${PREFIX}/libdata/pkgconfig#' \
		${WRKSRC}/libratbox/Makefile.in
# Fix BANDB path madness
	@${REINPLACE_CMD} -e 's#bandb_dpath != NULL#0#' \
		${WRKSRC}/bandb/rsdb_sqlite3.c

pre-su-install:
	@${MKDIR} ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/charybdis-oper-guide.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
