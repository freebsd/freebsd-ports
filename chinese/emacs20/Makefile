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

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts \
		xcin2.5:${PORTSDIR}/chinese/xcin25
.endif

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

post-install:
	${INSTALL} -c ${.CURDIR}/files/Emacs ${PREFIX}/share/emacs/${PORTVERSION}/etc
	${INSTALL} -c ${.CURDIR}/files/dot.emacs ${PREFIX}/share/emacs/${PORTVERSION}/etc
	@${CAT} ${PKGMESSAGE}

.include "${MASTERDIR}/Makefile"
