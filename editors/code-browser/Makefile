# ex:ts=8
# Ports collection makefile for:	code-browser
# Date created:			Jan 25, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	code-browser
PORTVERSION=	1.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Folding Text Editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GCC=	3.4+
USE_GNOME=	gtk20
USE_REINPLACE=	yes

PLIST_FILES=	bin/code-browser \
		%%DATADIR%%/languages.cb-config \
		%%DATADIR%%/user-preferences.cb-config
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386; signal 11 errors during build"
.endif

post-patch:
.for file in Makefile zinc/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g ; \
		 s|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s| make| $$(MAKE)|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code-browser \
		${PREFIX}/bin/code-browser
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config/languages.cb-config \
		${DATADIR}/languages.cb-config
	${INSTALL_DATA} ${WRKSRC}/config/user-preferences-x.cb-config \
		${DATADIR}/user-preferences.cb-config

.include <bsd.port.post.mk>
