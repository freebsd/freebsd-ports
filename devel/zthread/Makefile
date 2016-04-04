# Created by: pvh@egenetics.com
# $FreeBSD$

PORTNAME=	zthread
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ZThread/${PORTVERSION}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform-independent object-oriented C++ threading library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ftime --disable-static
MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -delete

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.orig' -or -name '*.swp' \) -delete
	@${REINPLACE_CMD} -E 's,(bin|data|inlude)dir\),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libZThread.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
