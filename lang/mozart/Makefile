# New ports collection makefile for:   mozart
# Date created:        23. June 2000
# Whom:                Mathias Picker <mathiasp@virtual-earth.de>
#
# $FreeBSD$
#

PORTNAME=	mozart
PORTVERSION=	1.1.0.20000207
CATEGORIES=	lang tk80
MASTER_SITES=	ftp://ftp.mozart-oz.org/pub/mozart/${PORTVERSION}/tar/ \
		ftp://ftp.sics.se/pub/mozart/${PORTVERSION}/tar/
DISTFILES=	${DISTNAME}-src.tar.gz ${MOZART_DOCS}
.if !defined(NOPORTDOCS)
DISTFILES+=	${MOZART_DOCS}
.endif

MAINTAINER=	mathiasp@virtual-earth.de

BUILD_DEPENDS=	xemacs:${PORTSDIR}/editors/xemacs21
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

MOZART_DOCS=	mozart-1.1.0.20000207-doc.tar.gz

SCRIPTS_ENV=	LN=${LN} PERL=${PERL}
ALL_TARGET=
MAKE_ARGS=	PREFIX=${PREFIX}/lib/oz
USE_BISON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_XLIB=	yes
# magic wand: set INSTALL to some absurd value, or else
# mozart's configure will not find the right install
# when configuring as root.
CONFIGURE_ENV=	INSTALL=${CHMOD}
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/oz  --disable-doc \
	--with-inc-dir=${LOCALBASE}/include/tcl8.0,${LOCALBASE}/include/tk8.0 \
	--with-lib-dir=${LOCALBASE}/lib --with-tcl-lib=${LOCALBASE}/lib \
	--with-tk-lib=${LOCALBASE}/lib

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

post-install:
.if !defined(NOPORTDOCS)
	${TAR} --unlink -xzpf ${DISTDIR}/${MOZART_DOCS} \
		-C ${PREFIX}/lib/oz
	${RM} -rf ${PREFIX}/lib/oz/doc
	${MV} ${PREFIX}/lib/oz/mozart/doc ${PREFIX}/lib/oz
	${RM} -rf ${PREFIX}/lib/oz/mozart
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
