# New ports collection makefile for:   gnuserv-emacs20
# Date created:        10 February 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	gnuserv
PORTVERSION=	3.12.3
CATEGORIES=	editors
MASTER_SITES=	http://meltin.net/hacks/emacs/src/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org

HAS_CONFIGURE=	yes

EMACS_PORT_NAME?=emacs20

CONFIGURE_ARGS=	--prefix=${PREFIX}

PORTDOCDIR=	share/doc/gnuserv-${EMACS_PORT_NAME}
MAN1=		gnuserv.1
MLINKS=		gnuserv.1 gnuattach.1 \
		gnuserv.1 gnuclient.1 \
		gnuserv.1 gnudoit.1
DOCS=		COPYING ChangeLog INSTALL README README.orig
SOURCES=	devices.el gnuserv-compat.el gnuserv.el
ELCS=		${SOURCES:S/.el/.elc/g}

PLIST_SUB=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

lispdir=	${PREFIX}/${EMACS_SITE_LISPDIR}/gnuserv
post-install:
	${MKDIR} ${lispdir};
.for i in ${SOURCES} ${ELCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${lispdir}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
