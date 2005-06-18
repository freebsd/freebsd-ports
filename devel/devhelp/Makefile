# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	devhelp
PORTVERSION=	0.10
CATEGORIES?=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C,^([[:digit:]]+\.[[:digit:]]+).*,\1,}
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Developer help browser for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
GCONF_SCHEMAS=	devhelp.schemas
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mozilla=${MOZILLA}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,g;s,^@dirrm share/((gnome/[^d]|pixmaps|application|locale).*|gnome$$),,;s,^@dirrm etc/gconf.*,,;s,^etc/gconf/gconf.*,,'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default the port uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  firefox       "
	@${ECHO_MSG} ""


post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%MOZILLA%%|${MOZILLA}|g' \
		${FILESDIR}/devhelp.sh > ${WRKDIR}/devhelp.sh

post-install:
	@${INSTALL_SCRIPT} -m 555 ${WRKDIR}/devhelp.sh ${PREFIX}/etc/rc.d/000.devhelp.sh
	@ldconfig -m ${X11BASE}/lib/${MOZILLA}

.include <bsd.port.post.mk>
