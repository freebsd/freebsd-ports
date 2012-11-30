# Created by: lazyklimm <lazyklimm@gmail.com>
# $FreeBSD$

PORTNAME=	qsynth
PORTVERSION=	0.3.6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application

LIB_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth

USE_QT4=	gui qmake_build moc_build uic_build rcc_build linguist_build
QT_NONSTANDARD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LOCALBASE}/bin/lupdate-qt4 \
		ac_cv_path_ac_lrelease=${LOCALBASE}/bin/lrelease-qt4
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${QT_INCDIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${QT_LIBDIR} ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|@make |@$$(MAKE) | ; \
		 /man1/s|^|#|' ${WRKSRC}/Makefile.in

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o qsynth.mak \
		${QMAKEFLAGS})

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qsynth

.include <bsd.port.mk>
