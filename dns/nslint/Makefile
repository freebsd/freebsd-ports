# New ports collection makefile for:	nslint
# Date created:		27 October 1997
# Whom:			dglo@ssec.wisc.edu
#
# $FreeBSD$
#

PORTNAME=	nslint
PORTVERSION=	2.1.a6
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		http://critical.ch/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/a/}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perform consistency checks on DNS zone files

GNU_CONFIGURE=	yes

ALL_TARGET=	${PORTNAME}
INSTALL_TARGET=	install install-man

BOOTFILE?=	/etc/namedb/named.boot
CONFFILE?=	/etc/namedb/named.conf

MAN8=		nslint.8
PLIST_FILES=	bin/nslint

post-patch:
	${REINPLACE_CMD} -e '/^\ \{4\}V_CCOPT/d' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/etc/named.boot|${BOOTFILE}|; \
		s|/etc/named.conf|${CONFFILE}|' \
			${WRKSRC}/${PORTNAME}.c \
			${WRKSRC}/${MAN8}

.include <bsd.port.mk>
