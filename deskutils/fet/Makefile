# New ports collection makefile for:	fet
# Date created:				11 March 2010
# Whom:					Leinier Cruz Salfran <salfrancl@yahoo.es>
#
# $FreeBSD$
#

PORTNAME=	fet
PORTVERSION=	5.14.2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://lalescu.ro/liviu/fet/download/ \
		http://lalescu.ro/liviu/fet/download/old/ \
		http://timetabling.de/download/ \
		http://timetabling.de/download/old/

MAINTAINER=	salfrancl@yahoo.es
COMMENT=	FET is free timetabling software

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network qt3support xml \
		moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
QMAKE_ARGS=	-unix PREFIX=${PREFIX} \
		INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2

PLIST_FILES=	bin/fet
MAN1=		fet.1
.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

DESKTOP_ENTRIES=	"FET" \
			"Free timetable software" \
			"" \
			"fet" \
			"Application;Education;Qt;" \
			true

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet ${PREFIX}/bin
	${MKDIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/fet.1 ${PREFIX}/man/man1
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \. ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
