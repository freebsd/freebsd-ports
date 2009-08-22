# ex:ts=8
# New ports collection makefile for:	HT Editor
# Date created:			Jun 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hte
PORTVERSION=	2.0.17
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/ht-source/${PORTVERSION}
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A file editor/viewer/analyzer for executables

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ht

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	Does not build on ia64
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS=--disable-x11-textmode
.else
USE_XORG=	x11
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
