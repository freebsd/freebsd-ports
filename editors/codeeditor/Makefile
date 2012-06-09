# New ports collection makefile for:    codeeditor
# Date created:         3 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	codeeditor
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	editors gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	codeeditor
DISTNAME=	CodeEditor-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	CodeEditor is a text and code editor for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/CodeEditor
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

post-patch:
	${REINPLACE_CMD} -e 's| bool| mybool|' -e 's|(bool|(mybool|' \
		${WRKSRC}/CodeEditorView/CodeEditorViewPreference.h \
		${WRKSRC}/CodeEditorView/CodeEditorViewPreference.m \
		${WRKSRC}/CodeEditorView/BlockHandler.h \
		${WRKSRC}/CodeEditorView/CodeEditorView.h \
		${WRKSRC}/CodeEditorView/CodeEditorView.m \
		${WRKSRC}/CodeEditor/DocumentController.m \
		${WRKSRC}/LanguageHandler/ObjCHandler/ObjCBlockHandler.m

.include <bsd.port.mk>
