# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	libshhmsg
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhmsg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for displaying messages

OPTIONS_DEFINE=	DOCS

USES=	uidfix
MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CREDITS README shhmsg.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
