#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Please view me with 4 column tabs!

# Please make sure all changes to this file are past through the maintainer. 
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
KDE_MAINTAINER=		will@FreeBSD.org

# This section contains the USE_ definitions.
# XXX: Write HAVE_ definitions sometime.

# USE_QT_VER		- Says that the port uses the Qt toolkit.  Possible values:
#					  1, 2, or 3; each specify the major version of Qt to use.
# USE_KDELIBS_VER	- Says that the port uses KDE libraries.  Possible values:
#					  1, 2, or 3; each specify the major version of KDE to use.
#					  This implies USE_QT of the appropriate version.
# USE_KDEBASE_VER	- Says that the port uses the KDE base.  Possible values:
#					  1, 2, or 3; each specify the major version of KDE to use.
#					  This implies USE_KDELIBS of the appropriate version.

#
# WARNING!  ACHTUNG!  DANGER WILL ROBINSON!
# DO NOT USE USE_QT_VER=1 UNLESS YOU WILL NOT BE NEEDING ANY ASSISTANCE
# WHATSOEVER FROM THE MAINTAINER OF THIS FILE!
#

# Compat shims.
.if defined(USE_QT)
USE_QT_VER=		2
pre-everything::
	@${ECHO} ">>> Warning:  this port needs to be updated as it uses the old-style USE_QT variable!"
.endif # defined(USE_QT)

# tagged MASTER_SITE_KDE_kde
kmaster=				${MASTER_SITE_KDE:S@%/@%/:kde@g}
.if !defined(MASTER_SITE_SUBDIR)
MASTER_SITE_KDE_kde=	${kmaster:S@%SUBDIR%/@@g}
.else
ksub=${MASTER_SITE_SUBDIR}
MASTER_SITE_KDE_kde=	${kmaster:S@%SUBDIR%/@${ksub}/@g}
.endif # !defined(MASTER_SITE_SUBDIR)

# USE_KDEBASE_VER section
.if defined(USE_KDEBASE_VER)
.if ${USE_KDEBASE_VER} == CVS
LIB_DEPENDS+=	konq:${PORTSDIR}/x11/kdebase
USE_KDELIBS_VER=CVS
.elif ${USE_KDEBASE_VER} == 3
# kdebase 3.x common stuff
LIB_DEPENDS+=	konq:${PORTSDIR}/x11/kdebase3
USE_KDELIBS_VER=3
.else
# kdebase 2.x common stuff -- DEFAULT
USE_KDELIBS_VER=2
.endif # ${USE_KDEBASE_VER} == 3
.endif # defined(USE_KDEBASE_VER)

# USE_KDELIBS_VER section
.if defined(USE_KDELIBS_VER)
.if ${USE_KDELIBS_VER} == CVS
LIB_DEPENDS+=	kwalletbackend:${PORTSDIR}/x11/kdelibs
USE_QT_VER=		CVS
PREFIX=			${KDE_CVS_PREFIX}
.elif ${USE_KDELIBS_VER} == 3
# kdelibs 3.x common stuff
LIB_DEPENDS+=	kwalletbackend:${PORTSDIR}/x11/kdelibs3
USE_QT_VER=		3
PREFIX=			${KDE_PREFIX}
.else
BROKEN=			"Unknown value in USE_KDELIBS_VER"
# kdelibs 2.x common stuff -- DEFAULT
USE_QT_VER=		2
.endif # ${USE_KDELIBS_VER} == 3
.endif # defined(USE_KDELIBS_VER)

# End of USE_KDELIBS_VER section

# USE_QT_VER section
.if defined(USE_QT_VER)
# Qt 1.x common stuff
.if ${USE_QT_VER} == 1
LIB_DEPENDS+=  qt1.3:${PORTSDIR}/x11-toolkits/qt145
MOC?=                  ${X11BASE}/bin/moc1
.if defined(PREFIX)
QTDIR=                 ${PREFIX}
.else
QTDIR=                 ${X11BASE}
.endif # defined(PREFIX)
CONFIGURE_ENV+=        MOC="${MOC}" QTDIR="${QTDIR}"

.elif ${USE_QT_VER} == CVS

KDE_CVS_PREFIX?=	${LOCALBASE}/kde-cvs
QT_CVS_PREFIX?=		${X11BASE}/qt-cvs
QTCPPFLAGS?=
QTCFGLIBS?=

MOC?=				${QT_CVS_PREFIX}/bin/moc
BUILD_DEPENDS+=		${MOC}:${PORTSDIR}/x11-toolkits/qt-copy
RUN_DEPENDS+=		${MOC}:${PORTSDIR}/x11-toolkits/qt-copy
QTCPPFLAGS+=		-D_GETOPT_H		# added to work around broken getopt.h #inc
.if !defined (QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-extra-libs="${LOCALBASE}/lib" \
				--with-extra-includes="${LOCALBASE}/include"
CONFIGURE_ENV+=	MOC="${MOC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" LIBS="${QTCFGLIBS}" \
				QTDIR="${QT_CVS_PREFIX}" KDEDIR="${KDE_CVS_PREFIX}"
.endif

.elif ${USE_QT_VER} == 3

# Yeah, it's namespace pollution, but this is really the best place for this
# stuff. Arts does NOT use it anymore.
KDE_VERSION=		3.2.0
KDE_ORIGVER=	${KDE_VERSION}
KDE_PREFIX?=	${LOCALBASE}

QTCPPFLAGS?=
QTCGFLIBS?=

# Qt 3.x common stuff
QT_PREFIX?=		${X11BASE}
MOC?=			${QT_PREFIX}/bin/moc
#LIB_DEPENDS+=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt32
BUILD_DEPENDS+=	${QT_PREFIX}/bin/moc:${PORTSDIR}/x11-toolkits/qt32
RUN_DEPENDS+=	${QT_PREFIX}/bin/moc:${PORTSDIR}/x11-toolkits/qt32
QTCPPFLAGS+=	-I${LOCALBASE}/include -I${PREFIX}/include \
				-I${QT_PREFIX}/include -D_GETOPT_H
QTCFGLIBS+=		-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -ljpeg \
				-L${QT_PREFIX}/lib
.if !defined(QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-qt-includes=${QT_PREFIX}/include \
				--with-qt-libraries=${QT_PREFIX}/lib \
				--with-extra-libs=${LOCALBASE}/lib \
				--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ENV+=	MOC="${MOC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" LIBS="${QTCFGLIBS}"
.endif # !defined(QT_NONSTANDARD)

.else # QT2

QTCPPFLAGS?=
QTCGFLIBS?=

# Qt 2.x common stuff -- DEFAULT
LIB_DEPENDS+=	qt2.4:${PORTSDIR}/x11-toolkits/qt23
QTNAME=			qt2
MOC?=			${X11BASE}/bin/moc2
QTCPPFLAGS+=	-D_GETOPT_H -I${LOCALBASE}/include -I${PREFIX}/include \
				-I${X11BASE}/include/qt2
QTCFGLIBS+=		-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -ljpeg -lgcc -lstdc++
.if !defined(QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
				--with-qt-libraries=${X11BASE}/lib \
				--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-l${QTNAME}" \
				CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" LIBS="${QTCFGLIBS}"
.endif # !defined(QT_NONSTANDARD)

.endif # USE_QT_VER == ???
.endif # defined(USE_QT_VER)

# End of USE_QT_VER section

# Assemble plist from parts
# <alane@freebsd.org> 2002-12-06
.if defined(KDE_BUILD_PLIST)
PLIST?=			${WRKDIR}/plist
PLIST_BASE?=	plist.base
PLIST_APPEND?=
plist_base=${FILESDIR}/${PLIST_BASE}
plist_base_rm=${FILESDIR}/${PLIST_BASE}.rm
plist_append=${PLIST_APPEND:C:([A-Za-z0-9._]+):${FILESDIR}/\1:}
plist_append_rm=${PLIST_APPEND:C:([A-Za-z0-9._]+):${FILESDIR}/\1.rm:}
kde-plist:
	${CAT} ${plist_base} ${plist_append} 2>/dev/null >${PLIST}
	-${CAT} ${plist_append_rm} ${plist_base_rm} 2>/dev/null >>${PLIST};true
.PHONY: kde-plist
pre-build: kde-plist
.endif # defined(KDE_BUILD_PLIST)
