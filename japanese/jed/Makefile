# New ports collection makefile for:	Jed text editor w/ Japanese support
# Date created:		2 Feb 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese editors
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.kondara.org/~g/slang/
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}-B${VERSION:R}-${VERSION:E}__J${JP_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-extralibs-${VERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A SLang-based text editor (w/ Japanese support)

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang \
		${LIBDEP_CANNA}

VERSION=	0.99.8
JP_VERSION=	067

DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JED_ROOT="${JED_ROOT}" X_EXTRA_LIBS="-lcurses"
CONFIGURE_ARGS=	--enable-x-locale=no
ALL_TARGET=	${BINSTUFF} getmail
MAN1=		jed.1 rgrep.1

JED_ROOT=	${PREFIX}/lib/jed
BINSTUFF=	jed rgrep

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CANNA)
CONFIGURE_ARGS+=	--with-canna=no
.else
CONFIGURE_ARGS+=	--with-canna=yes
LIBDEP_CANNA=		canna.1:${PORTSDIR}/japanese/Canna
.endif

# XJED core dumps on 3.x-STABLE for the present.
.if ${OSVERSION} < 400000
XJED_BROKEN=	yes
.endif

.if defined(WITHOUT_X11)
WITHOUT_XJED=	yes
.endif

.if defined(WITHOUT_XJED) || defined(XJED_BROKEN)
PLIST_SUB=	XJED_ENTRY="@comment xjed is not installed"
.else
USE_XLIB=	yes
BINSTUFF+=	xjed
PLIST_SUB=	XJED_ENTRY="bin/xjed"
.endif

_OBJDIR=	${WRKSRC}/src/${ARCH}objs
_DOCDIR=	${WRKSRC}/doc
_INFODIR=	${WRKSRC}/info
_LIBDIR=	${WRKSRC}/lib

pre-fetch:
.if !defined(WITHOUT_CANNA)
	@${ECHO_MSG} "To build this port without Canna, define \"WITHOUT_CANNA\"."
.endif
.if !defined(WITHOUT_XJED)
.if defined(XJED_BROKEN)
	@${ECHO_MSG} "Sorry, I will not build xjed since it is broken on 3.x-STABLE for the present."
.else
	@${ECHO_MSG} "To build this port without xjed, define \"WITHOUT_XJED\"."
.endif
.endif

post-extract:
	@cd ${WRKDIR} && ${MV} *.sl ${_LIBDIR}/

post-patch:
	@${RM} ${_INFODIR}/*.orig

do-install:
	@${MKDIR} ${JED_ROOT}
.for d in bin doc lib lib/colors lib/tm
	@${MKDIR} ${JED_ROOT}/${d}
.endfor
.for f in ${BINSTUFF}
	${INSTALL_PROGRAM} ${_OBJDIR}/${f} ${PREFIX}/bin/
.endfor
	${INSTALL_PROGRAM} ${_OBJDIR}/getmail ${JED_ROOT}/bin/
	${INSTALL_DATA} ${_LIBDIR}/*.sl ${_LIBDIR}/*.dat ${_LIBDIR}/*.hlp ${_LIBDIR}/jed.rc ${JED_ROOT}/lib/
	${INSTALL_DATA} ${_LIBDIR}/colors/* ${JED_ROOT}/lib/colors/
	${INSTALL_DATA} ${_LIBDIR}/tm/* ${JED_ROOT}/lib/tm/
.for f in ${MAN1}
	${INSTALL_MAN} ${_DOCDIR}/${f} ${PREFIX}/man/man1/
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${_INFODIR}/jed.* ${PREFIX}/info/
	@install-info ${PREFIX}/info/jed.info ${PREFIX}/info/dir
	@${MKDIR} ${JED_ROOT}/doc/
	${INSTALL_DATA} ${_DOCDIR}/README ${_DOCDIR}/*.txt ${_DOCDIR}/jed.tex ${WRKSRC}/jed-j.doc ${JED_ROOT}/doc/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
