# New ports collection makefile for:   gnusget
# Date created:        19 January 2006
# Whom:                Ilya A. Otyutskiy <ilya.otyutskiy@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gnusget
PORTVERSION=	0.5.1
CATEGORIES=	ftp
MASTER_SITES=	http://edge.pp.ru/gnusget/ \
		http://fb.roolz.org/gnusget/ \
		http://dragomir.best-hosting.ru/gnusget/ \
		http://ve7.vtx.ru/gnusget/ \
		http://coddex.pp.ru/gnusget/ \
		ftp://nightflame.no-ip.org/gnusget/

MAINTAINER=	ilya.otyutskiy@gmail.com
COMMENT=	Shell-extension for wget, which uses download- and history-file

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

PLIST_FILES=	bin/gnusget

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/gnusget ${PREFIX}/bin

.include <bsd.port.mk>
