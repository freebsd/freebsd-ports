# New ports collection makefile for:   last.fm
# Date created:        February 5th, 2007
# Whom:                Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	last.fm
PORTVERSION=	1.3.2.14
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/client/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Official last.fm radio player

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui imageformats_run moc_build network qmake_build rcc_build \
		sql uic_build xml
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=4.2+
.endif

post-patch:
	${REINPLACE_CMD} -e 's|bash|sh|g' -e 's|qmake|${QMAKE}|g' \
			-E -e 's|(.*"CONFIG-=debug")|\1 ${QMAKEFLAGS}|g' \
			-e 's|function header|header()|g' \
			-e 's|function middle|middle()|g' \
			-e 's|-pthread|-pthread -R/usr/local/share/last.fm|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|linux\*|unix|g' ${WRKSRC}/src/src.pro

post-build:
	cd ${WRKSRC}/src/output/RtAudio && \
	${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} && make

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/last.fm ${PREFIX}/bin/last.fm
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/services
	${INSTALL_DATA} ${FILESDIR}/last.fm.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lastfm.protocol ${PREFIX}/share/services
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/bin/* ${DATADIR}/

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
