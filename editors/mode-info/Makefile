# New ports collection makefile for:	elisp-info.el
# Date Created:		21 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mode-info
PORTVERSION=	0.8.5
PORTREVISION=	8
CATEGORIES=	editors elisp
MASTER_SITES=	http://namazu.org/~tsuchiya/elisp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functions to refer Manuals on Emacsen with describe-* like interface

MI_INDEX+=	mi-emacs.idx
MI_WITH_ELISP?=	yes
MI_ELISP_LANG?=	en
MI_WITH_MAKE?=	yes

.if (${MI_WITH_ELISP} == "yes")
.if (${MI_ELISP_LANG} == "en")
BUILD_DEPENDS+=	${LOCALBASE}/info/elisp.info:${PORTSDIR}/lang/elisp-manual
RUN_DEPENDS+=	${LOCALBASE}/info/elisp.info:${PORTSDIR}/lang/elisp-manual
.else
IGNORE=	cannot install: MI_ELISP_LANG should be "en"
.endif
MI_INDEX+=	mi-elisp.idx
PLIST_SUB+=	MI_WITH_ELISP=""
.else
PLIST_SUB+=	MI_WITH_ELISP="@comment "
.endif

.if (${MI_WITH_MAKE} == "yes")
BUILD_DEPENDS+= ${LOCALBASE}/info/make.info:${PORTSDIR}/devel/gmake
RUN_DEPENDS+=	${LOCALBASE}/info/make.info:${PORTSDIR}/devel/gmake
MI_INDEX+=	mi-make.idx
PLIST_SUB+=	MI_WITH_MAKE=""
.else
PLIST_SUB+=	MI_WITH_MAKE="@comment "
.endif

USE_EMACS=	yes

.include <bsd.port.pre.mk>

LISPDIR?=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mode-info
ALL_TARGET=	default index
#INSTALL_TARGET=	install install-index

post-configure:
.if (${MI_ELISP_LANG} == "en")
	${ECHO_CMD} "(setq mode-info-elisp-titles (list \"elisp\"))" >> ${WRKSRC}/elisp-comp
.elif (${MI_ELISP_LANG} == "ja")
	${ECHO_CMD} "(setq mode-info-elisp-titles (list \"elisp-ja\"))" >> ${WRKSRC}/elisp-comp
.endif
	${ECHO_CMD} "(setq mode-info-make-titles (list \"make\"))" >> ${WRKSRC}/elisp-comp
post-install:
.for i in ${MI_INDEX}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mode-info/
.endfor
	${RM} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mode-info/ChangeLog
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README README.ja ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
