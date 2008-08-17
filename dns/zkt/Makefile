# New ports collection makefile for:   zkt
# Date created:        2008-08-06
# Whom:                Frank Behrens <frank+ports@ilse.behrens.de>
#
# $FreeBSD$
#

PORTNAME=		zkt
PORTVERSION=		0.97
CATEGORIES=		dns
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.hznet.de/dns/zkt/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		frank+ports@ilse.behrens.de
COMMENT=		Tool to manage keys and signatures for DNSSEC-zones

DIR_NAMED_CONF?=	/etc/namedb

PLIST_FILES=		sbin/dnssec-zkt \
			sbin/dnssec-signer \
			sbin/zkt-soaserial
MAN8=			dnssec-zkt.8 dnssec-signer.8
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${DIR_NAMED_CONF}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-zkt ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-signer ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/dnssec-zkt.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/dnssec-signer.8 ${PREFIX}/man/man8/

.include <bsd.port.post.mk>
