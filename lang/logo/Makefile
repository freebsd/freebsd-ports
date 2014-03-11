# Created by: jkh
# $FreeBSD$

PORTNAME=	ucblogo
PORTVERSION=	5.5
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.berkeley.edu/~bh/downloads/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brian Harvey's logo language interpreter

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
.if defined(EMACS_LOGO_MODE)
USE_EMACS=	yes
.endif

.if defined(WITH_FULL_DOCS)
.undef NOPORTDOCS
USE_TEX=	tex:build
USE_GHOSTSCRIPT=yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XORG=	x11 ice sm
MAKEFILE=	makefile
HAS_CONFIGURE=	yes

ALL_TARGET=	all

.if defined(WITH_FULL_DOCS) || defined(EMACS_LOGO_MODE)
USE_GMAKE=	yes
MAKE_ENV+=	LIBLOC="${PREFIX}/lib/logo" BINDIR="${PREFIX}/bin" DOCSDIR="${DOCSDIR}" INFODIR="${PREFIX}/${INFO_PATH}"
.endif

.if defined(WITH_FULL_DOCS)
INFO=		ucblogo loops
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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
	@${ECHO_MSG} ""
.endif

do-install:
.for d in lib/logo lib/logo/logolib \
	lib/logo/helpfiles
	${MKDIR} ${PREFIX}/$d
.endfor
	${MKDIR} ${EXAMPLESDIR}/csls
	${INSTALL_PROGRAM} ${WRKSRC}/logo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/logolib/* ${PREFIX}/lib/logo/logolib/
	${INSTALL_DATA} ${WRKSRC}/helpfiles/* ${PREFIX}/lib/logo/helpfiles/
	${INSTALL_DATA} ${WRKSRC}/csls/* ${EXAMPLESDIR}/csls/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usermanual ${DOCSDIR}
.endif
.if defined(WITH_FULL_DOCS)
	cd ${WRKSRC}/docs/ ;${SETENV} ${MAKE_ENV} ${GMAKE} install
.endif
.ifdef defined(EMACS_LOGO_MODE)
	cd ${WRKSRC}/emacs; ${SETENV} ${MAKE_ENV} ${GMAKE} install-emacs
.endif
.include <bsd.port.post.mk>
