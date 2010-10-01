# New ports collection makefile for:	vym
# Date created:				17 Oct 2004
# Whom:			Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	vym
PORTVERSION=	1.12.7
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	VYM  (View Your Mind) is a tool to generate and manipulate maps

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build qt3support network xml
QMAKE_ARGS=	PREFIX=${PREFIX} \
		DATADIR=${DATADIR:S,/vym,,} \
		DOCDIR=${DOCSDIR}

MAKE_JOBS_SAFE=	yes
STRIP_FILES=	bin/vym

DESKTOP_ENTRIES=	"VYM" \
			"Put the things you have got in your mind into a map" \
			"${DATADIR}/icons/vym.png" \
			"vym" \
			"" \
			false

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/INSTALLS += doc/d' ${WRKSRC}/vym.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${QMAKEFLAGS} ${QMAKE_ARGS} vym.pro

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.mk>
