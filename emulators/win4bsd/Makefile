# New ports collection Makefile for:	win4bsd
# Date created:		17 Nov 2006
# Whom:			Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	win4bsd
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.v-bridges.com/pub/archive/pro/releases/bsd/pro/${PORTVERSION}/
DISTNAME=	Win4BSD-1.1_63918_i386-freebsd
EXTRACT_SUFX=	.tbz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Win4BSD Virtual Machine for Windows under BSD

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
RUN_DEPENDS=	kqemu-kmod>1.3.0.p11:${PORTSDIR}/emulators/kqemu-kmod \
		xwininfo:${PORTSDIR}/x11/xwininfo

BROKEN=		does not fetch
DEPRECATED=	Development has ceased and distfile is no longer available
EXPIRATION_DATE=2010-12-31
CONFLICTS=	Win4BSD-[0-9]*

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	installs an i386 binary which requires dependecies
USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
RESTRICTED=	Redistribution is not allowed

PKGDEINSTALL=	${WRKSRC}/+POST-DEINSTALL

SUB_FILES=	pkg-message

POST_PATCH_REMOVE_FILES=	\
	usr/local/lib/win4bsd/bin/postinstall.sh.orig \
	usr/local/lib/win4bsd/etc/mergepro_rc.orig \
	usr/local/lib/win4bsd/etc/rc.Win4BSD.orig

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/+POST-* \
		${WRKSRC}/usr/local/lib/win4bsd/bin/postinstall.sh \
		${WRKSRC}/usr/local/share/applications/kde/*.desktop \
		${WRKSRC}/usr/local/lib/win4bsd/etc/rc.Win4BSD
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/usr/local/lib/win4bsd/etc/mrgprossv.sh
.for file in ${POST_PATCH_REMOVE_FILES}
	@${RM} ${WRKSRC}/${file}
.endfor

do-install:
	${CP} -R ${WRKSRC}/usr/local/* ${PREFIX}
	${CP} -R ${WRKSRC}/usr/share/* ${PREFIX}/share

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
