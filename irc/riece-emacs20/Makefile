# New ports collection makefile for:	liece
# Date Created:		9 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	liece
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	irc elisp
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim-${EMACS_PORT_NAME}-current \
		${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
RUN_DEPENDS+=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim-${EMACS_PORT_NAME}-current

EMACS_PORT_NAME?=	emacs20
LISPDIR?=		${EMACS_LIBDIR}/site-lisp/${PORTNAME}
ETCDIR?=		share/${PORTNAME}
PKGINFODIR?=		"@comment "

# INFODIR is system reserved
EMACS_INFODIR?=		info
DIRSECTION?=		"The Emacs editor and associated tools"
INFOENTRY?=		"* Liece: (liece).		IRC client on Emacsen."

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-emacs="${EMACS_CMD}"
ALL_TARGET=	all sample.dot.emacs
PLIST_SUB=	EMACS_NAME=${EMACS_NAME} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		EMACS_ONLY=${EMACS_ONLY} \
		LISPDIR=${LISPDIR} \
		ETCDIR=${ETCDIR} \
		EMACS_INFODIR=${EMACS_INFODIR} \
		PKGINFODIR=${PKGINFODIR} \
		DIRSECTION=${DIRSECTION}

DOCS=		AUTHORS lisp/ChangeLog

FLIM_VER=	1.13.2
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-${FLIM_VER}.FreeBSD-packages

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == xemacs
XEMACS_ONLY?=		""
EMACS_ONLY?=		"@comment "
.else
XEMACS_ONLY?=		"@comment "
EMACS_ONLY?=		""
.endif

post-install:
	${MKDIR} ${PREFIX}/${ETCDIR}/po/ja_JP.EUC/LC_MESSAGES
	${LN} -sf ja_JP.EUC ${PREFIX}/${ETCDIR}/po/ja
	msgfmt -o ${PREFIX}/${ETCDIR}/po/ja_JP.EUC/LC_MESSAGES/liece.mo ${WRKSRC}/etc/po/ja.po	
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/sample.dot.emacs ${PREFIX}/${ETCDIR}/
	${MKDIR} ${PREFIX}/${ETCDIR}/doc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${ETCDIR}/doc/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/liece.info ${PREFIX}/${EMACS_INFODIR}/
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} \
		${PREFIX}/${EMACS_INFODIR}/liece.info ${PREFIX}/${EMACS_INFODIR}/dir
.endif

.include <bsd.port.post.mk>
