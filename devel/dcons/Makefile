# New ports collection makefile for:	dcons
# Date created:				2003/05/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dcons
PORTVERSION=	20030818
PORTREVISION=	0
CATEGORIES=	devel sysutils
MASTER_SITES=	http://people.FreeBSD.org/~simokawa/firewire/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Dumb CONSole device driver

NO_WRKSUBDIR=	yes
MANCOMPRESSED=	yes

MAN4=		dcons.4 dcons_crom.4
MAN8=		fwchat.8

PKGMESSAGE=	${WRKSRC}/pkg-message

.include <bsd.port.pre.mk>
KMODDIR=	${PREFIX}/lib/dcons
MAKE_ENV=	KMODDIR=${KMODDIR} \
		BINDIR=${PREFIX}/sbin \
		MANDIR=${MANPREFIX}/man/man
MKNOD?=		/sbin/mknod
MAKEDEV=	/dev/MAKEDEV
DCONS_DEV=	/dev/dcons
DCONS_MAJOR=	184
DCONS_MINOR=	0
DCONS_MODE=	0622
PLIST_SUB=	KMODDIR=${KMODDIR} MKNOD=${MKNOD} MAKEDEV=${MAKEDEV} \
		DCONS_DEV=${DCONS_DEV} \
		DCONS_MAJOR=${DCONS_MAJOR} DCONS_MINOR=${DCONS_MINOR} \
		DCONS_MODE=${DCONS_MODE}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/share::man::man4::Makefile \
				${WRKSRC}/share/man/man4/Makefile

post-build:
	@${SED} "s,%%DOCSDIR%%,${DOCSDIR}," \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

pre-install:
	@${MKDIR} ${PREFIX}/lib/dcons
	@${INSTALL_SCRIPT} ${FILESDIR}/dcons.sh ${PREFIX}/etc/rc.d/
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.dcons ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/usr.sbin/fwchat/gdb-usage ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/usr.sbin/fwchat/sample-script ${DOCSDIR}/
	if [ -x ${MAKEDEV} ]; then \
		${RM} -f ${DCONS_DEV}; \
		${MKNOD} ${DCONS_DEV} c ${DCONS_MAJOR} ${DCONS_MINOR}; \
		${CHMOD} ${DCONS_MODE} ${DCONS_DEV}; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
