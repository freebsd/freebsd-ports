# New ports collection makefile for:	dcons
# Date created:				2003/05/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dcons
PORTVERSION=	20030525
CATEGORIES=	devel sysutils
MASTER_SITES=	http://people.FreeBSD.org/~simokawa/firewire/

MAINTAINER=	simokawa@FreeBSD.org
COMMENT=	Dumb CONSole device driver

NO_WRKSUBDIR=	yes
MANCOMPRESSED=	yes

MAN4=		dcons.4
MAN8=		fwchat.8

PKGMESSAGE=	${WRKSRC}/pkg-message

KMODDIR=	${PREFIX}/lib/dcons
MAKE_ENV=	KMODDIR=${KMODDIR} \
		BINDIR=${PREFIX}/bin \
		MANDIR=${MANPREFIX}/man/man
PLIST_SUB=	KMODDIR=${KMODDIR}

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
