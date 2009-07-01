# ex:ts=8
# Ports collection makefile for:	code-browser
# Date created:			Jan 25, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	code-browser
PORTVERSION=	3.11
CATEGORIES=	editors
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Folding Text Editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_GMAKE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}-3

PORTDOCS=	code-browser.chm doc.css doc.html
PLIST_FILES=	bin/code-browser \
		%%DATADIR%%/config/preferences.cbc \
		%%DATADIR%%/config-default/preferences.cbc \
		%%DATADIR%%/config-optional/AVR-asm.cbc \
		%%DATADIR%%/config-optional/perforce.cbc \
		%%DATADIR%%/config-optional/torque.cbc
PLIST_DIRS=	%%DATADIR%%/config-optional \
		%%DATADIR%%/config-default \
		%%DATADIR%%/config \
		%%DATADIR%%

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=		i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	does not build on ${ARCH}; signal 11 errors during build

.if ${ARCH} != "i386"
MAKE_ARGS+=	MODE=64
.endif

post-patch:
.for file in Makefile zinc/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g ; \
		 s|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s| make| $$(MAKE)|g ; \
		 s|@$$(|$$(|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code-browser ${PREFIX}/bin
.for dir in config config-default config-optional
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.* ${DATADIR}/${dir}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
