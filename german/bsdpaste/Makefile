# Created by: Aron Schlesinger <as@bsdgroup.de>
# $FreeBSD$

PORTNAME=	bsdpaste
PORTVERSION=	1.0.1
CATEGORIES=	german ruby
MASTER_SITES=	http://people.bsdgroup.de/~as/bsdpaste/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pastebin web application to upload and read text on a webserver

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	ruby18

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsdpaste.rb \
		${STAGEDIR}${PREFIX}/bin/bsdpaste

.include <bsd.port.mk>
