# New ports collection makefile for:   mozart
# Date created:        23. June 2000
# Whom:                Mathias Picker <mathiasp@virtual-earth.de>
#
# $FreeBSD$
#

PORTNAME=	mozart
PORTVERSION=	1.2.4.20020829
CATEGORIES=	lang tk83 parallel
MASTER_SITES=	ftp://ftp.mozart-oz.org/pub/mozart/${PORTVERSION}/tar/ \
		ftp://ftp.sics.se/pub/mozart/${PORTVERSION}/tar/
DISTFILES=	${DISTNAME}-src.tar.gz ${MOZART_DOCS}
.if !defined(NOPORTDOCS)
DISTFILES+=	${MOZART_DOCS}
.endif

MAINTAINER=	mathiasp@virtual-earth.de

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

MOZART_DOCS=	mozart-${PORTVERSION}-doc.tar.gz

SCRIPTS_ENV=	LN=${LN} PERL=${PERL}
ALL_TARGET=
MAKE_ARGS=	PREFIX=${PREFIX}/lib/oz
USE_BISON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_XLIB=	yes
USE_AUTOCONF_VER=	213
# magic wand: set INSTALL to some absurd value, or else
# mozart's configure will not find the right install
# when configuring as root.
CONFIGURE_ENV=	INSTALL=${CHMOD}
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/oz --disable-doc \
	--with-inc-dir=${LOCALBASE}/include/tcl8.3,${LOCALBASE}/include/tk8.3 \
	--with-lib-dir=${LOCALBASE}/lib --with-tcl-lib=${LOCALBASE}/lib \
	--with-tk-lib=${LOCALBASE}/lib \
	--with-tkinclude=${LOCALBASE}/include/tk8.3

pre-extract:
	@${ECHO}
	@${ECHO} -----------------------------------------------------
	@${ECHO}
	@${ECHO} If you have problems building mozart,
	@${ECHO} deinstall any old version of mozart
	@${ECHO} and unset OZHOME
	@${ECHO}
	@${ECHO} ----------------------------------------------------
	@${ECHO}

post-patch:
	cd ${WRKSRC}/contrib/gtk \
		&& ${AUTOCONF} ${AUTOCONF_ARGS} -l ${WRKSRC}
	cd ${WRKSRC}/platform/emulator \
		&& ${AUTOCONF} ${AUTOCONF_ARGS} -l ${WRKSRC}
	cd ${WRKSRC}/platform/tools/gump/ozflex \
		&& ${AUTOCONF} ${AUTOCONF_ARGS} -l ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${TAR} --unlink -xzpf ${DISTDIR}/${MOZART_DOCS} \
		-C ${PREFIX}/lib/oz
	@${RM} -rf ${PREFIX}/lib/oz/doc
	@${MV} ${PREFIX}/lib/oz/mozart/doc ${PREFIX}/lib/oz
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/oz/doc
	@${FIND} ${PREFIX}/lib/oz -type d -print0 \
		| ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${PREFIX}/lib/oz/doc -type f -print0 \
		| ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${RM} -rf ${PREFIX}/lib/oz/mozart
.endif
	@cd ${PREFIX} ; ${FIND} lib/oz -type f -o -type l | sort \
		> ${WRKDIR}/PLIST.lib-oz
	@cd ${PREFIX} ; ${FIND} lib/oz -type d | sort -r \
	    	| ${SED} -e 's/^/@dirrm /g' \
		>> ${WRKDIR}/PLIST.lib-oz
	@${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.lib-oz"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"			>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.lib-oz"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-lib-oz
	@cd ${WRKDIR} ; ex < ex.script
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
