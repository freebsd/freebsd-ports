# New ports collection makefile for:   bnc
# Date created:        06 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	bnc
PORTVERSION=	2.9.4
CATEGORIES=	irc
MASTER_SITES=	http://home.risingnet.net/download/ \
		http://bnc.acmeshells.com/ \
		http://www.sourcefiles.org/System/Servers/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	douglas@t2web.com.br
COMMENT=	A simple IRC relay proxy with support for virtual hosting

GNU_CONFIGURE=	YES

DOCS=		COPYING Changelog README example.conf
BINS=		bnc mkpasswd
SCRIPTS=	bncchk bncsetup

.include <bsd.port.pre.mk>

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/bncsetup

do-install:
	@${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/,} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/etc/bnc.conf.sample

.include <bsd.port.post.mk>
