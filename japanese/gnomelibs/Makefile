# New ports collection makefile for:	Japanese gnome-libs
# Date created:        28 October 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	1.4.1.3
CATEGORIES=	japanese x11 gnome

MASTERDIR=	${.CURDIR}/../../x11/gnomelibs

EXTRA_PATCHES=	${.CURDIR}/files/patch-*

MAINTAINER=	ports@FreeBSD.org

PLIST=		${WRKDIR}/pkg-plist

post-extract:
	${ECHO_CMD} bin/gnome-libs-jp > ${PLIST}
	${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

post-install:
	${TOUCH} ${PREFIX}/bin/gnome-libs-jp
	${CHMOD} 755 ${PREFIX}/bin/gnome-libs-jp

# The following hackery is only necessary so that we can mark this
# slave port, but not the master port, as broken on 5.x.  Once that
# is fixed, everything past this point except the line '.include
# "${MASTERDIR}/Makefile' should be removed.
BEFOREPORTMK=	yes
.include "${MASTERDIR}/Makefile"
.undef BEFOREPORTMK

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.include <bsd.port.post.mk>
