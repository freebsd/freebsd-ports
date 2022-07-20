PORTNAME=	libshhmsg
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	shhmsg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for displaying messages

LICENSE=	ART10

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CREDITS README shhmsg.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
