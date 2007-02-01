# ex:ts=8
# New ports collection makefile for:	HT Editor
# Date created:			Jun 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hte
PORTVERSION=	0.9.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	mva@sysfault.org
COMMENT=	A file editor/viewer/analyzer for executables

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/ht

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	does not build on ia64
.endif

.if ${ARCH} == "amd64" && ${OSVERSION} > 700000
BROKEN=	does not build on 7.x for amd64
.endif

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS=--disable-x11-textmode
.else
USE_XLIB=	yes
CPPFLAGS=	-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|typedef unsigned int uint;||g' ${WRKSRC}/global.h
	@${REINPLACE_CMD} -e \
		's|uint |UINT |g' ${WRKSRC}/htdata.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
