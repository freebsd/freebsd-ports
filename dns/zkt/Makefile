# New ports collection makefile for:   zkt
# Date created:        2008-08-06
# Whom:                Frank Behrens <frank+ports@ilse.behrens.de>
#
# $FreeBSD$
#

PORTNAME=		zkt
DISTVERSION=		0.99c
CATEGORIES=		dns
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-v${DISTVERSION} \
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
MAKE_JOBS_SAFE=		yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/var/named/|${DIR_NAMED_CONF}/|g' ${WRKSRC}/man/*.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-zkt ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-signer ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-signer.8 ${PREFIX}/man/man8/

.include <bsd.port.post.mk>
