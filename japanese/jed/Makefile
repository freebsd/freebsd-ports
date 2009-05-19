# New ports collection makefile for:	Jed text editor w/ Japanese support
# Date created:		2 Feb 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	5
CATEGORIES=	japanese editors
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.kondara.org/~g/slang/
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}-B${VERSION:R}-${VERSION:E}__J${JP_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extralibs-${VERSION}.tar.gz

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A SLang-based text editor (w/ Japanese support)

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang

VERSION=	0.99.8
JP_VERSION=	067

DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JED_ROOT="${JED_ROOT}" X_EXTRA_LIBS="-lcurses"
CONFIGURE_ARGS=	--enable-x-locale=no
ALL_TARGET=	${BINSTUFF} getmail
MAN1=		jed.1 rgrep.1
.if !defined(NOPORTDOCS)
INFO=		jed
.endif

MAKE_JOBS_UNSAFE=  yes

JED_ROOT=	${DATADIR}
BINSTUFF=	jed rgrep

OPTIONS=	CANNA	"Canna support"	on \
		X11	"X11 support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CANNA)
CONFIGURE_ARGS+=	--with-canna=no
.else
CONFIGURE_ARGS+=	--with-canna=yes
LIB_DEPENDS+=		canna.1:${PORTSDIR}/japanese/canna-lib
.endif

.if defined(WITHOUT_X11)
PLIST_SUB=	X11="@comment "
.else
USE_XORG=	x11 xext xt
BINSTUFF+=	xjed
PLIST_SUB=	X11="bin/xjed"
.endif

_OBJDIR=	${WRKSRC}/src/${ARCH}objs
_DOCDIR=	${WRKSRC}/doc
_INFODIR=	${WRKSRC}/info
_LIBDIR=	${WRKSRC}/lib

PORTDOCS= abbrev.txt color.txt dfa.txt edt.txt emacs.txt fold.txt	\
	hooks.txt ide-mode.txt jed_faq.txt jedfuns.txt libfuns.txt	\
	menus.txt mouse.txt pc-keys.txt program.txt rgrep.txt		\
	rmail.txt script.txt slangfun.txt syntax.txt undo.txt wjed.txt	\
	wordstar.txt xjed.txt yankpop.txt README jed.tex jed-j.doc

post-extract:
	@cd ${WRKDIR} && ${MV} *.sl ${_LIBDIR}/
	@${CP} ${WRKSRC}/jed-j.doc ${_DOCDIR}/

post-patch:
	@${RM} ${_INFODIR}/*.orig

do-install:
	${MKDIR} ${JED_ROOT}
	cd ${JED_ROOT} && ${MKDIR} bin lib lib/colors lib/tm
	cd ${_OBJDIR} && ${INSTALL_PROGRAM} ${BINSTUFF} ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${_OBJDIR}/getmail ${JED_ROOT}/bin/
	${INSTALL_DATA} ${_LIBDIR}/*.sl \
		${_LIBDIR}/*.dat \
		${_LIBDIR}/*.hlp \
		${_LIBDIR}/jed.rc \
		${JED_ROOT}/lib/
	${INSTALL_DATA} ${_LIBDIR}/colors/* ${JED_ROOT}/lib/colors/
	${INSTALL_DATA} ${_LIBDIR}/tm/* ${JED_ROOT}/lib/tm/
	cd ${_DOCDIR} && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${_INFODIR}/jed.info ${PREFIX}/info/
	${INSTALL_DATA} ${_INFODIR}/jed.1in ${PREFIX}/info/jed.info-1
	${INSTALL_DATA} ${_INFODIR}/jed.2in ${PREFIX}/info/jed.info-2
	${INSTALL_DATA} ${_INFODIR}/jed.3in ${PREFIX}/info/jed.info-3
	${MKDIR} ${DOCSDIR}
	cd ${_DOCDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
