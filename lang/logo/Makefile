# New ports collection makefile for:	logo
# Date created:		22 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	ucblogo
PORTVERSION=	5.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cs.berkeley.edu/pub/ucblogo/
MASTER_SITE_SUBDIR=non-gnu/ucblogo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brian Harvey's logo language interpreter

.if defined(EMACS_LOGO_MODE)
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs19
.endif
.if defined(WITH_FULL_DOCS)
.undef NOPORTDOCS

BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX \
		ps2pdf:${PORTSDIR}/${GHOSTSCRIPT_PORT}
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

pre-everything::
.if !defined(EMACS_LOGO_MODE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define EMACS_LOGO_MODE to build the emacs logo mode"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_FULL_DOCS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_FULL_DOCS to build ps, pdf and html docs"
	@${ECHO_MSG} "      This requires teTeX and ghostscript !"
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
.endif
	@${ECHO_MSG} ""
.endif

do-install:
.for d in lib/logo lib/logo/logolib \
	lib/logo/helpfiles share/examples/logo/csls
	${MKDIR} ${PREFIX}/$d
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/logo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/logolib/* ${PREFIX}/lib/logo/logolib/
	${INSTALL_DATA} ${WRKSRC}/helpfiles/* ${PREFIX}/lib/logo/helpfiles/
	${INSTALL_DATA} ${WRKSRC}/csls/* ${PREFIX}/share/examples/logo/csls/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usermanual ${DOCSDIR}
.endif
.if defined(WITH_FULL_DOCS)
	cd ${WRKSRC}/emacs/ ;${SETENV} ${MAKE_ENV} ${GMAKE} install-docs
.endif
.ifdef defined(EMACS_LOGO_MODE)
	cd ${WRKSRC}/emacs; ${SETENV} ${MAKE_ENV} ${GMAKE} install-emacs
.endif
.include <bsd.port.mk>
