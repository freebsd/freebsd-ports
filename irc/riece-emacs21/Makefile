# New ports collection makefile for:	liece (for emacs21)
# Date Created:		9 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	liece
PORTVERSION=	1.4.6
CATEGORIES=	irc elisp
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX} \
		${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX} \
		${LOCALBASE}/bin/ldcc:${PORTSDIR}/irc/liece-dcc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

FLIM_TRUNK=	1.14
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages

EMACS_PORT_NAME?=	emacs21

DIRSECTION?=		"The Emacs editor and associated tools"
INFOENTRY?=		"* Liece: (liece).		IRC client on Emacsen."

.if ${EMACS_PORT_NAME} == "emacs21"
DEPPORT_SUFFIX=		
.else
DEPPORT_SUFFIX=		-${EMACS_PORT_NAME}
.endif

.if ${EMACS_PORT_NAME} == xemacs21-mule
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages
LISPDIR=		${EMACS_PACKAGESDIR}/lisp
EMACS_ETCDIR=		${EMACS_PACKAGESDIR}/etc
EMACS_INFODIR=		${EMACS_PACKAGESDIR}/info
PKGINFODIR=		${EMACS_PACKAGESDIR}/pkginfo
CONFIGURE_ARGS=		--with-xemacs=${EMACS_CMD} \
			--with-packagedir=${EMACS_PACKAGESDIR} \
			--datadir=${PREFIX}/${EMACS_ETCDIR}
ALL_TARGET=		package
INSTALL_TARGET=		install-package
XEMACS_ONLY=		""
EMACS_ONLY=		"@comment "
.else
LISPDIR=		${EMACS_VERSION_SITE_LISPDIR}
EMACS_ETCDIR=		share
EMACS_INFODIR=		info
PKGINFODIR=		"@comment "
CONFIGURE_ARGS=		--with-emacs=${EMACS_CMD} \
			--with-lispdir=${PREFIX}/${LISPDIR} \
			--datadir=${PREFIX}/${EMACS_ETCDIR}
MAKE_ARGS+=		LISPDIR=${PREFIX}/${LISPDIR}
XEMACS_ONLY=		"@comment "
EMACS_ONLY=		""
.endif
LIECE_ETCDIR=	${EMACS_ETCDIR}/${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/lisp
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST_SUB=	EMACS_NAME=${EMACS_NAME} \
		XEMACS_ONLY=${XEMACS_ONLY} EMACS_ONLY=${EMACS_ONLY} \
		LISPDIR=${LISPDIR}/${PORTNAME} LIECE_ETCDIR=${LIECE_ETCDIR} \
		PKGINFODIR=${PKGINFODIR} \
		EMACS_INFODIR=${EMACS_INFODIR} \
		DIRSECTION=${DIRSECTION} INFOENTRY=${INFOENTRY}

DOCS=		AUTHORS lisp/ChangeLog

post-build:
	(cd ${WRKSRC}/etc/po ; msgfmt -o liece.mo ja.po)
	(cd ${WRKSRC}/etc ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} sample.dot.emacs)
post-install:
	(cd ${WRKSRC}/etc ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/etc/icons/*.xpm ${PREFIX}/${LIECE_ETCDIR}/icons
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/po/ja_JP.EUC/LC_MESSAGES
	${LN} -sf ja_JP.EUC ${PREFIX}/${LIECE_ETCDIR}/po/ja
	${INSTALL_DATA} ${WRKSRC}/etc/po/liece.mo ${PREFIX}/${LIECE_ETCDIR}/po/ja_JP.EUC/LC_MESSAGES
.if !defined(NOPORTDOCS)
#	${INSTALL_DATA} ${WRKSRC}/etc/sample.dot.emacs ${PREFIX}/${LIECE_ETCDIR}/
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/doc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${LIECE_ETCDIR}/doc/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/liece.info ${PREFIX}/${EMACS_INFODIR}/
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} \
		${PREFIX}/${EMACS_INFODIR}/liece.info ${PREFIX}/${EMACS_INFODIR}/dir
.endif

.include <bsd.port.mk>
