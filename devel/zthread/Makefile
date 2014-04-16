# Created by: pvh@egenetics.com
# $FreeBSD$

PORTNAME=	zthread
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ZThread/${PORTVERSION}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform-independent object-oriented C++ threading library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ftime --disable-static
USES=		gmake
MAKE_ARGS+=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
MAKE_ENV+=	SED=sed # req'd for LIBTOOL?!
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -delete

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.orig' -or -name '*.swp' \) -delete
	@${REINPLACE_CMD} -E 's,(bin|data|inlude)dir\),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
