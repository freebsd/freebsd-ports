# ex:ts=8
# Ports collection makefile for:  emacs20 with XIM and a little zh-l10n
# Date created:			  Sat Nov 11, 2000
# Whom:				  Clive Lin <clive@CirX.ORG>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../editors/emacs20

MAINTAINER=	clive@FreeBSD.org

DEPRECATED=	emacs20 and related ports are obsolete; please use a more recent version
EXPIRATION_DATE=	2007-08-19

WITH_XPG4=	yes

PKGMESSAGE=	${.CURDIR}/pkg-message

PLIST=		${WRKDIR}/pkg-plist

pre-patch:
	@( cd ${WRKSRC}; \
		${PATCH} -sp1 < ${.CURDIR}/files/emacs20-xim-20000713.diff ; )

post-patch:
	@${ECHO_CMD} "share/emacs/%%EMACS_VER%%/etc/Emacs" >> ${WRKDIR}/pkg-plist
	@${ECHO_CMD} "share/emacs/%%EMACS_VER%%/etc/dot.emacs" >> ${WRKDIR}/pkg-plist
	@${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/pkg-plist

post-install::
	${INSTALL} -c ${.CURDIR}/files/Emacs ${PREFIX}/share/emacs/${PORTVERSION}/etc
	${INSTALL} -c ${.CURDIR}/files/dot.emacs ${PREFIX}/share/emacs/${PORTVERSION}/etc
	@${CAT} ${PKGMESSAGE}

.include "${MASTERDIR}/Makefile"
