# New ports collection makefile for:	liece (for emacs21)
# Date Created:		9 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	liece
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	irc elisp
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${FLIM_BRANCH:S/.//}-${EMACS_PORT_NAME} \
		${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${FLIM_BRANCH:S/.//}-${EMACS_PORT_NAME} \
		${LOCALBASE}/bin/ldcc:${PORTSDIR}/irc/liece-dcc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

FLIM_BRANCH=	1.13
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_BRANCH}.FreeBSD-packages

EMACS_PORT_NAME?=	emacs21
CONFIGURE_ARGS+=	--with-emacs=${EMACS_CMD} --datadir=${PREFIX}/${EMACS_ETCDIR}

DIRSECTION?=		"The Emacs editor and associated tools"
INFOENTRY?=		"* Liece: (liece).		IRC client on Emacsen."

.if ${EMACS_PORT_NAME} == xemacs21-mule
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages
LISPDIR=		${EMACS_PACKAGESDIR}/lisp
EMACS_ETCDIR=		${EMACS_PACKAGESDIR}/etc
EMACS_INFODIR=		${EMACS_PACKAGESDIR}/info
PKGINFODIR=		${EMACS_PACKAGESDIR}/pkginfo
CONFIGURE_ARGS+=	--enable-package
XEMACS_ONLY=		""
EMACS_ONLY=		"@comment "
.else
LISPDIR=		${EMACS_VERSION_SITE_LISPDIR}
EMACS_ETCDIR=		share
EMACS_INFODIR=		info
PKGINFODIR=		"@comment "
MAKE_ARGS+=		LISPDIR=${PREFIX}/${LISPDIR}
XEMACS_ONLY=		"@comment "
EMACS_ONLY=		""
.endif
LIECE_ETCDIR=	${EMACS_ETCDIR}/${PORTNAME}

ALL_TARGET=	all sample.dot.emacs
PLIST_SUB=	EMACS_NAME=${EMACS_NAME} \
		XEMACS_ONLY=${XEMACS_ONLY} EMACS_ONLY=${EMACS_ONLY} \
		LISPDIR=${LISPDIR}/${PORTNAME} LIECE_ETCDIR=${LIECE_ETCDIR} \
		PKGINFODIR=${PKGINFODIR} \
		EMACS_INFODIR=${EMACS_INFODIR} \
		DIRSECTION=${DIRSECTION} INFOENTRY=${INFOENTRY}

DOCS=		AUTHORS lisp/ChangeLog

post-install:
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/po/ja_JP.EUC/LC_MESSAGES
	${LN} -sf ja_JP.EUC ${PREFIX}/${LIECE_ETCDIR}/po/ja
	msgfmt -o ${PREFIX}/${LIECE_ETCDIR}/po/ja_JP.EUC/LC_MESSAGES/liece.mo ${WRKSRC}/etc/po/ja.po
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/sample.dot.emacs ${PREFIX}/${LIECE_ETCDIR}/
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/doc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${LIECE_ETCDIR}/doc/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/liece.info ${PREFIX}/${EMACS_INFODIR}/
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} \
		${PREFIX}/${EMACS_INFODIR}/liece.info ${PREFIX}/${EMACS_INFODIR}/dir
.endif

.include <bsd.port.mk>
