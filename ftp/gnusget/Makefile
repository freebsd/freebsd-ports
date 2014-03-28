# Created by: Ilya A. Otyutskiy <ilya.otyutskiy@gmail.com>
# $FreeBSD$

PORTNAME=	gnusget
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://fb.roolz.org/gnusget/

MAINTAINER=	ilya.otyutskiy@gmail.com
COMMENT=	Shell-extension for wget which uses download- and history-file

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

PLIST_FILES=	bin/gnusget

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/gnusget ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
