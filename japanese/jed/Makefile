# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	jed
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	6
CATEGORIES=	japanese editors
MASTER_SITES=	LOCAL/knu \
		http://www.kondara.org/~g/slang/
DISTNAME=	${PORTNAME}-B${VERSION:R}-${VERSION:E}__J${JP_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extralibs-${VERSION}.tar.gz
DIST_SUBDIR=	jed

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLang-based text editor (w/ Japanese support)

LIB_DEPENDS=	libslang.so:japanese/libslang

VERSION=	0.99.8
JP_VERSION=	067

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JED_ROOT="${JED_ROOT}" X_EXTRA_LIBS="-lncurses"
CONFIGURE_ARGS=	--enable-x-locale=no
ALL_TARGET=	${BINSTUFF} getmail
MAKE_JOBS_UNSAFE=	yes
INFO=		jed

JED_ROOT=	${DATADIR}
BINSTUFF=	jed rgrep

OPTIONS_DEFINE=	DOCS X11 CANNA
OPTIONS_DEFAULT=CANNA X11
OPTIONS_SUB=	yes

CANNA_DESC=		Canna support
CANNA_CONFIGURE_ON=	--with-canna=yes
CANNA_CONFIGURE_OFF=	--with-canna=no
CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib

X11_USES=	xorg
X11_USE=	XORG=x11,xext,xt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
BINSTUFF+=	xjed
.endif

_OBJDIR=	${WRKSRC}/src/${ARCH}objs
_DOCDIR=	${WRKSRC}/doc
_INFODIR=	${WRKSRC}/info
_LIBDIR=	${WRKSRC}/lib

PORTDOCS=	abbrev.txt color.txt dfa.txt edt.txt emacs.txt fold.txt	\
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
	@${MKDIR} ${STAGEDIR}${JED_ROOT}
	@(cd ${STAGEDIR}${JED_ROOT} && ${MKDIR} bin lib lib/colors lib/tm)
	(cd ${_OBJDIR} && ${INSTALL_PROGRAM} ${BINSTUFF} ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_PROGRAM} ${_OBJDIR}/getmail ${STAGEDIR}${JED_ROOT}/bin
	(cd ${_LIBDIR} && ${INSTALL_DATA} *.sl *.dat *.hlp jed.rc \
		${STAGEDIR}${JED_ROOT}/lib)
	${INSTALL_DATA} ${_LIBDIR}/colors/* ${STAGEDIR}${JED_ROOT}/lib/colors
	${INSTALL_DATA} ${_LIBDIR}/tm/* ${STAGEDIR}${JED_ROOT}/lib/tm
	(cd ${_DOCDIR} && ${INSTALL_MAN} jed.1 rgrep.1 \
		${STAGEDIR}${PREFIX}/man/man1)
	${INSTALL_DATA} ${_INFODIR}/jed.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${_INFODIR}/jed.1in ${STAGEDIR}${PREFIX}/${INFO_PATH}/jed.info-1
	${INSTALL_DATA} ${_INFODIR}/jed.2in ${STAGEDIR}${PREFIX}/${INFO_PATH}/jed.info-2
	${INSTALL_DATA} ${_INFODIR}/jed.3in ${STAGEDIR}${PREFIX}/${INFO_PATH}/jed.info-3
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${_DOCDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
