# New ports collection makefile for:	linguist
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linguist
PORTVERSION=	0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.trolltech.com/qt/pre-releases/
DISTNAME=	${PORTNAME}-pre

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for generating translations of strings used in i10 Qt programs

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
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

pre-configure:
	@${FIND} ${WRKSRC} -name '*.pro' | ${XARGS} ${REINPLACE_CMD} -E -e \
		's/(^CONFIG.*)/\1 thread/'

post-configure:
	@${REINPLACE_CMD} -e 's|\$$(SUBDIRS):.*tmake_all|\$$(SUBDIRS):|' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|TARGET.*=.*\$$(QTDIR)/bin/|TARGET=|'

do-install:
.for file in linguist lrelease lupdate qm2ts
	${INSTALL_PROGRAM} ${WRKSRC}/${file}/${file} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/doc/linguist
	${INSTALL_MAN} ${WRKSRC}/linguist/tutorial/doc/html/* ${PREFIX}/share/doc/linguist

.include <bsd.port.post.mk>
