# New ports collection makefile for:    juke
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

PORTNAME=		juke
PORTVERSION=		0.6
PORTREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.nocrew.org/software/juke/archive/

MAINTAINER=		oyvindmo@initio.no

GNU_CONFIGURE=		yes

MAN1=			juke.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${PREFIX}/etc/juke.conf.sample
	@${SED} 's,PREFIX,${PREFIX},' ${PKGMESSAGE}

.include <bsd.port.mk>
