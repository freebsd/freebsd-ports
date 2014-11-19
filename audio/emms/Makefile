# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	emms
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	audio elisp
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Emacs Multi-Media System

LICENSE=	GPLv3

USES=		gmake makeinfo
USE_EMACS=	yes
MAKE_ENV=	SITELISP="${PREFIX}/${EMACS_SITE_LISPDIR}/emms" \
		INSTALLINFO="${TRUE}"

INFO=		emms

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(DESTDIR\)=|\1?=| ; \
		 s|^\(PREFIX\)=$$(DESTDIR)|\1?=| ; \
		 s|^\(INFODIR\)=|\1?=| ; \
		 s|^\(MAN1DIR\)=$$(PREFIX)/share|\1?=$$(PREFIX)| ; \
		 s|^\(SITELISP\)=|\1?=| ; \
		 s|^\(INSTALLINFO\) =|INSTALLINFO ?=| ; \
		 s| \($$(SITELISP)\)| $$(DESTDIR)\1|g ; \
		 s| \($$(INFODIR)\)| $$(DESTDIR)\1|g ; \
		 s|\($$(INFODIR)\)/emms|\1| ; \
		 s| \($$(MAN1DIR)\)| $$(DESTDIR)\1|g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
