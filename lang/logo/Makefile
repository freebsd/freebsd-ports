# New ports collection makefile for:	logo
# Date created:		22 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	ucblogo
PORTVERSION=	5.1
CATEGORIES=	lang
MASTER_SITES= 	${MASTER_SITE_GNU} \
		ftp://ftp.cs.berkeley.edu/pub/ucblogo/
MASTER_SITE_SUBDIR=non-gnu/ucblogo

WRKSRC=		${WRKDIR}/ucblogo

.if defined(EMACS_LOGO_MODE)
BUILD_DEPENDS=  emacs:${PORTSDIR}/editors/emacs
.endif
.if defined(WITH_FULL_DOCS)
.undef NOPORTDOCS
BUILD_DEPENDS+= tex:${PORTSDIR}/print/teTeX \
		ps2pdf:${PORTSDIR}/print/ghostscript-gnu
.endif

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
MAKEFILE=	makefile
HAS_CONFIGURE=	yes

ALL_TARGET=	all

.if defined(WITH_FULL_DOCS)
ALL_TARGET+=	docs
PLIST_SUB+=	WITH_FULL_DOCS=""
.else
PLIST_SUB+=	WITH_FULL_DOCS="@comment "
.endif

.if defined(EMACS_LOGO_MODE)
ALL_TARGET+=	logo-mode
PLIST_SUB+=	EMACS_LOGO_MODE=""
.else
PLIST_SUB+=	EMACS_LOGO_MODE="@comment "
.endif

pre-fetch:
.if !defined(EMACS_LOGO_MODE)
	@${ECHO} ""
	@${ECHO} "      Define EMACS_LOGO_MODE to build the emacs logo mode"
	@${ECHO} ""
.endif
.if !defined(WITH_FULL_DOCS)
	@${ECHO} ""
	@${ECHO} "      Define WITH_FULL_DOCS to build ps, pdf and html docs"
	@${ECHO} "      This requires teTeX and ghostscript !"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
