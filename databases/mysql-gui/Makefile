# New ports collection makefile for:    mysql-gui
# Date created:				August 17 2001
# Whom:	      				Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	mysql-gui
PORTVERSION=	1.7.5
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://mysql.ftp.cvut.cz/Downloads/%SUBDIR%/ \
		http://sunsite.informatik.rwth-aachen.de/mysql/Downloads/%SUBDIR%/ \
		http://mysql.he.net/Downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	mysqlgui
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	A graphical SQL client for MySQL

LIB_DEPENDS=	sqlplus.1:${PORTSDIR}/databases/mysql++ \
 		glut.3:${PORTSDIR}/graphics/libglut \
 		jpeg.9:${PORTSDIR}/graphics/jpeg \
 		fleditor.1:${PORTSDIR}/x11-toolkits/fl_editor \
		flvw.1:${PORTSDIR}/x11-toolkits/flvw
PATCH_DEPENDS=	${X11BASE}/include/FL/Fl_Editor.H:${PORTSDIR}/x11-toolkits/fl_editor

USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-src-/}
MAKE_ARGS=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

# Local Variables
#

OLD_FILES=	Fl_Editor.h Fl_FancyEditor.h Fl_ProgressBox.h \
		Fl_StatusPanel.h Flv_CStyle.H Flv_List.H Flv_Style.H \
		Flv_Table.H Flve_Check_Button.H Flve_Combo.H Flve_Input.H \
		editor.h math.h strings.h vartypes.h wstrings.h
NEW_FILES=	Fl_Editor.H editengine.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		Does not build
.endif

# Post-extract
#

post-extract: remove-inc

remove-inc:
.for file in ${OLD_FILES}
	@${RM} -f ${WRKSRC}/FL/${file}
.endfor

# Pre-patch
#

pre-patch: copy-inc
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/Fl_Help.cc

copy-inc:
.for file in ${NEW_FILES}
	@${CP} ${X11BASE}/include/FL/${file} ${WRKSRC}/FL/
.endfor

.include <bsd.port.post.mk>
