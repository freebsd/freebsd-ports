# New ports collection makefile for:	conquest
# Date created:			Apr 9, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	conquest
PORTVERSION=	7.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.radscan.com/conquest/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	markp@FreeBSD.org

GNU_CONFIGURE=	yes
BINGRP=		conquest
SHAREGRP=	conquest

post-patch:
	${PERL} -pi -e "s|\@prefix\@/conquest|\@prefix\@|g; \
		s|^.+\@chgrp .\(CONQGROUP\) conq.+||g; \
		s|^.+\@chmod 2771 conq.+||g;" ${WRKSRC}/Makefile.in
	${PERL} -pi -e "s/# include <termio.h>//g" ${WRKSRC}/c_defs.h
	${PERL} -pi -e "s/-O2 -fPIC//g" ${WRKSRC}/configure
	${PERL} -pi -e "s|/opt/conquest|${PREFIX}|g; \
		s|etc/conquestrc|etc/conquest/conquestrc|g; \
		s|bin/conqdriv|libexec/conqdriv|g; \
		s|etc/conquest_common.img|etc/conquest/conquest_common.img|g; \
		s|etc/conquest.log|share/conquest/conquest.log|g; \
		s|etc/conqnews.doc|share/conquest/conqnews.doc|g; \
		s|etc/conquest.doc|share/conquest/conquest.doc|g;" \
		${WRKSRC}/defs.h ${WRKSRC}/conf.h ${WRKSRC}/README

do-install:
	@${SH} pkg-install ${PORTNAME} PRE-INSTALL
	${INSTALL_PROGRAM} -m 2550 ${WRKSRC}/conqai ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqdriv ${PREFIX}/libexec
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqoper ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conqstrat ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conquest ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/conquest
	${INSTALL_DATA} ${WRKSRC}/conqrule \
		${PREFIX}/etc/conquest/conqrule.sample
	${MKDIR} ${PREFIX}/share/conquest
	${INSTALL_DATA} ${WRKSRC}/conqnews.doc \
		${PREFIX}/share/conquest/conqnews.doc.sample
	${INSTALL_DATA} ${WRKSRC}/conquest.doc ${PREFIX}/share/conquest
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/conquest
	${INSTALL_DATA} ${WRKSRC}/SERVER.DOC ${WRKSRC}/README \
		${PREFIX}/share/doc/conquest
.endif
	@${SH} pkg-install ${PORTNAME} POST-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
