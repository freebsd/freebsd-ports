# New ports collection makefile for:	linguist
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linguist
PORTVERSION=	0.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.trolltech.com/qt/pre-releases/
DISTNAME=	${PORTNAME}-pre

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	2
USE_X_PREFIX=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	TMAKEPATH="${LOCALBASE}/share/tmake/freebsd-g++" \
		QTDIR="${X11BASE}"
MAKE_ENV=	TMAKEPATH="${LOCALBASE}/share/tmake/freebsd-g++" \
		QTDIR="${X11BASE}"
MAKE_ARGS=	-e

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-configure:
	@${PERL} -pi -e 's|\$\(SUBDIRS\):.*tmake_all|\$\(SUBDIRS\):|' \
		${WRKSRC}/Makefile
	@find ${WRKSRC} -name "Makefile" -type f | xargs ${PERL} -pi -e \
		's|TARGET.*=.*\$\(QTDIR\)/bin/|TARGET=|'

do-install:
.for file in linguist lrelease lupdate qm2ts
	${INSTALL_PROGRAM} ${WRKSRC}/${file}/${file} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/doc/linguist
	${INSTALL_MAN} ${WRKSRC}/linguist/tutorial/doc/html/* ${PREFIX}/share/doc/linguist

.include <bsd.port.post.mk>
