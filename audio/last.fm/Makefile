# New ports collection makefile for:   last.fm
# Date created:        February 5th, 2007
# Whom:                Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	last.fm
PORTVERSION=	1.1.3
CATEGORIES=	audio net
MASTER_SITES=	http://static.last.fm/client/Linux/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	Official last.fm radio player

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui imageformats moc network uic xml
HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-build:
	${REINPLACE_CMD} -e 's|`dirname $$0`|${DATADIR}|g' \
		${WRKSRC}/bin/last.fm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/last.fm ${PREFIX}/bin/last.fm
	${MKDIR} ${PREFIX}/share/services
	${INSTALL_DATA} ${FILESDIR}/lastfm.protocol ${PREFIX}/share/services
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/bin/* ${DATADIR}/

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
