# New ports collection makefile for:	regexxer
# Date created:				15 February 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=		regexxer
PORTVERSION=		0.8
CATEGORIES=		devel textproc gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			ftp://ftp.csx.cam.ac.uk/pub/software/programming/%SUBDIR%/:pcre \
			ftp://ftp.fu-berlin.de/unix/misc/%SUBDIR%/:pcre \
			ftp://ftp.tin.org/pub/libs/%SUBDIR%/:pcre
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PCRE_NAME}/:pcre
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
			${PCRE_NAME}-${PCRE_VERSION}${EXTRACT_SUFX}:pcre

MAINTAINER=		rui@ruilopes.com
COMMENT=		An interactive tool for performing search and replace operations

LIB_DEPENDS=		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
			glademm-2.4:${PORTSDIR}/devel/libglademm24

USE_BZIP2=		yes
USE_X_PREFIX=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		gnomehack gnomeprefix gnometarget intltool intlhack
CONFIGURE_ARGS=		PCRE_CONFIG="${PCRE_WRKDIR}/.install/bin/pcre-config"
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PCRE_NAME=		pcre
PCRE_VERSION=		4.5
PCRE_WRKDIR=		${WRKDIR}/${PCRE_NAME}-${PCRE_VERSION}

post-patch:
	@${REINPLACE_CMD} -E 's,(\$$\(PKG_(CFLAGS|LIBS)\)) (\$$\(PCRE_(CFLAGS|LIBS)\)),\3 \1,' ${WRKSRC}/src/Makefile.in

pre-configure:
	@(cd ${PCRE_WRKDIR} && \
		${ECHO_CMD} "Configuring PCRE... " && \
		${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		./configure --enable-utf8 --disable-shared --prefix="${PCRE_WRKDIR}/.install" && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${GREP} regexxer) > temp-pkg-plist

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif

.include <bsd.port.post.mk>
