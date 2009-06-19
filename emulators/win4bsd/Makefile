# New ports collection Makefile for:	win4bsd
# Date created:		17 Nov 2006
# Whom:			Jason W. Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	win4bsd
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.win4bsd.com/pub/releases/${PORTVERSION}/
DISTNAME=	Win4BSD-1.1_63918_i386-freebsd
EXTRACT_SUFX=	.tbz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Win4BSD Virtual Machine for Windows under BSD

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
RUN_DEPENDS=	xwininfo:${PORTSDIR}/x11/xwininfo

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

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys/kern)
IGNORE=		requires system source for installing kqemu, the accelerator that provides native CPU speed in Win4BSD.  Please install the system sources in /usr/src (e.g. using sysinstall), and run make again
.endif

SCHED_NAME!=	${SYSCTL} -n kern.sched.name
.if ${SCHED_NAME} != "4BSD"
IGNORE=		requires the traditional 4BSD scheduler. Please rebuild your kernel with options SCHED_4BSD, and run make again
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/+POST-* \
		${WRKSRC}/usr/local/lib/win4bsd/bin/postinstall.sh \
		${WRKSRC}/usr/local/share/applications/kde/*.desktop \
		${WRKSRC}/usr/local/lib/win4bsd/etc/rc.Win4BSD
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/usr/local/lib/win4bsd/etc/mrgprossv.sh

do-install:
	${CP} -R ${WRKSRC}/usr/local/* ${PREFIX}
	${CP} -R ${WRKSRC}/usr/share/* ${PREFIX}/share

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
