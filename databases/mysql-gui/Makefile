# New ports collection makefile for:    mysql-gui
# Date created:				August 17 2001
# Whom:	      				Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	mysql-gui
PORTVERSION=	1.7.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mirrors/mysql/Downloads/mysqlgui
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	cyrille.lefevre@laposte.net

LIB_DEPENDS=	sqlplus.1:${PORTSDIR}/databases/mysql++ \
 		intl.1:${PORTSDIR}/devel/gettext \
 		glut.3:${PORTSDIR}/graphics/Mesa3 \
 		jpeg.9:${PORTSDIR}/graphics/jpeg \
 		fleditor.1:${PORTSDIR}/x11-toolkits/fl_editor \
		flvw.1:${PORTSDIR}/x11-toolkits/flvw

USE_X_PREFIX=	yes
USE_MESA=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-src-/}
MAKE_ARGS=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OLD_FILES=	Fl_Editor.h Fl_FancyEditor.h Fl_ProgressBox.h \
		Fl_StatusPanel.h Flv_CStyle.H Flv_List.H Flv_Style.H \
		Flv_Table.H Flve_Check_Button.H Flve_Combo.H Flve_Input.H \
		editor.h math.h strings.h vartypes.h wstrings.h
NEW_FILES=	Fl_Editor.H editengine.h

post-extract: remove-inc

remove-inc:
.for file in ${OLD_FILES}
	@${RM} -f ${WRKSRC}/FL/${file}
.endfor

pre-patch: copy-inc

copy-inc:
.for file in ${NEW_FILES}
	@${CP} ${PREFIX}/include/FL/${file} ${WRKSRC}/FL/
.endfor

.include <bsd.port.mk>
