# New ports collection makefile for:	navi2ch for emacs20
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	navi2ch
PORTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	sf@FreeBSD.org

EMACS_PORT_NAME?=	emacs20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}

DOCDIR=		share/doc/ja/navi2ch
PACKAGESDIR=	lib/xemacs/site-packages
PLIST_SUB=	LISPDIR=${LISPDIR} \
		ETCDIR=${ETCDIR} \
		INFODIR=${INFODIR}

LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}
ETCDIR=		${EMACS_LIBDIR_WITH_VER}/etc/navi2ch
INFODIR=	info

.if ${EMACS_PORT_NAME} == xemacs21-mule
LISPDIR=	${PACKAGESDIR}/lisp
ETCDIR=		${PACKAGESDIR}/etc/navi2ch
INFODIR=	${PACKAGESDIR}/info
PLIST_SUB+=	FSF="@comment "
CONFIGURE_ARGS+=--with-packagedir=${PREFIX}/${PACKAGESDIR}
.else
PLIST_SUB+=	FSF=""
CONFIGURE_ARGS+=--with-lispdir=${PREFIX}/${LISPDIR}/navi2ch \
		--with-icondir=${PREFIX}/${ETCDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif
.for i in gikope.el navi2ch-logo.el navi2ch-migemo.el
	${INSTALL_DATA} ${WRKSRC}/contrib/$i ${PREFIX}/${LISPDIR}/navi2ch
.endfor

.include <bsd.port.mk>
