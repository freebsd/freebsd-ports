# New ports collection makefile for:	liece (for emacs21)
# Date Created:		9 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	liece
PORTVERSION=	1.4.10
CATEGORIES=	irc elisp
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Yet another IRC client which runs under Emacsen

BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/apel/install.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX} \
		msgfmt:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/apel/install.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX} \
		ldcc:${PORTSDIR}/irc/liece-dcc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

EMACS_PORT_NAME?=	emacs21

DIRSECTION?=		"The Emacs editor and associated tools"
INFOENTRY?=		"* Liece: (liece).		IRC client on Emacsen."

.if ${EMACS_PORT_NAME} == "emacs21"
DEPPORT_SUFFIX=		
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif

CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		--datadir=${PREFIX}/share
MAKE_ARGS+=	LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
LIECE_ETCDIR=	share/${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/lisp
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST_SUB=	LIECE_LISPDIR=${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME} \
		LIECE_ETCDIR=${LIECE_ETCDIR} \
		DIRSECTION=${DIRSECTION} INFOENTRY=${INFOENTRY}

DOCS=		AUTHORS lisp/ChangeLog

post-build:
	(cd ${WRKSRC}/etc/po ; msgfmt -o liece.mo ja.po)
post-install:
	(cd ${WRKSRC}/etc ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)
	${INSTALL_DATA} ${WRKSRC}/etc/gnu-emacs-user-config ${PREFIX}/${LIECE_ETCDIR}
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/etc/icons/*.xpm ${PREFIX}/${LIECE_ETCDIR}/icons
	${LN} -sf ja ${PREFIX}/${LIECE_ETCDIR}/locale/ja_JP.EUC
	${LN} -sf ja ${PREFIX}/${LIECE_ETCDIR}/locale/ja_JP.eucJP
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${LIECE_ETCDIR}/doc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${LIECE_ETCDIR}/doc/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/liece.info ${PREFIX}/info/
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} \
		${PREFIX}/info/liece.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
