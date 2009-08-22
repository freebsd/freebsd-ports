# New ports collection makefile for:	ZThread
# Date created:				23 May 2001
# Whom:					pvh@egenetics.com
#
# $FreeBSD$
#

PORTNAME=	zthread
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ZThread/${PORTVERSION}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A platform-independent object-oriented C++ threading library

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ftime --disable-static
USE_GMAKE=	yes
MAKE_ARGS+=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"
MAKE_ENV+=	SED=sed # req'd for LIBTOOL?!
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -delete

post-patch:
	@${FIND} ${WRKSRC} \( -name '*.orig' -or -name '*.swp' \) -delete

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
