# New ports collection makefile for:	logo
# Date created:		22 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	ucblogo
PORTVERSION=	5.2
CATEGORIES=	lang
MASTER_SITES= 	${MASTER_SITE_GNU} \
		ftp://ftp.cs.berkeley.edu/pub/ucblogo/
MASTER_SITE_SUBDIR=non-gnu/ucblogo

MAINTAINER=	ports@FreeBSD.org

.if defined(EMACS_LOGO_MODE)
BUILD_DEPENDS=  emacs:${PORTSDIR}/editors/emacs
.endif
.if defined(WITH_FULL_DOCS)
.undef NOPORTDOCS
BUILD_DEPENDS+= tex:${PORTSDIR}/print/teTeX \
		ps2pdf:${PORTSDIR}/print/ghostscript-gnu
.endif

USE_XLIB=	yes
MAKEFILE=	makefile
HAS_CONFIGURE=	yes

ALL_TARGET=	all

.if defined(WITH_FULL_DOCS) || defined(EMACS_LOGO_MODE)
USE_GMAKE=	yes
MAKE_ENV+=	LIBLOC="${PREFIX}/lib/logo" BINDIR="${PREFIX}/bin"
.endif

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

do-install:
.for d in lib/logo lib/logo/logolib \
	lib/logo/helpfiles share/examples/logo/csls share/doc/logo
	${MKDIR} ${PREFIX}/$d
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/logo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/logolib/* ${PREFIX}/lib/logo/logolib/
	${INSTALL_DATA} ${WRKSRC}/helpfiles/* ${PREFIX}/lib/logo/helpfiles/
	${INSTALL_DATA} ${WRKSRC}/csls/* ${PREFIX}/share/examples/logo/csls/
.if !defined(NOPORTSDOCS)
	${INSTALL_DATA} ${WRKSRC}/usermanual $(PREFIX)/share/doc/logo
.endif
.if defined(WITH_FULL_DOCS)
	cd ${WRKSRC}/emacs/ ;${SETENV} ${MAKE_ENV} ${GMAKE} install-docs
.endif
.ifdef defined(EMACS_LOGO_MODE)
	cd ${WRKSRC}/emacs; ${SETENV} ${MAKE_ENV} ${GMAKE} install-emacs
.endif
.include <bsd.port.mk>
